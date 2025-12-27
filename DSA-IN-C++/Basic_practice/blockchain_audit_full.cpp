#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <fstream>
#include <chrono>
typedef unsigned int uint32;
typedef unsigned long long uint64;
inline uint32 rotr(uint32 x, uint32 n) { return (x >> n) | (x << (32 - n)); }
inline uint32 Ch(uint32 x, uint32 y, uint32 z) { return (x & y) ^ (~x & z); }
inline uint32 Maj(uint32 x, uint32 y, uint32 z) { return (x & y) ^ (x & z) ^ (y & z); }
inline uint32 BSIG0(uint32 x) { return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22); }
inline uint32 BSIG1(uint32 x) { return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25); }
inline uint32 SSIG0(uint32 x) { return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3); }
inline uint32 SSIG1(uint32 x) { return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10); }
std::string sha256(const std::string &input) {
    static const uint32 K[64] = {
        0x428a2f98u,0x71374491u,0xb5c0fbcfu,0xe9b5dba5u,0x3956c25bu,0x59f111f1u,0x923f82a4u,0xab1c5ed5u,
        0xd807aa98u,0x12835b01u,0x243185beu,0x550c7dc3u,0x72be5d74u,0x80deb1feu,0x9bdc06a7u,0xc19bf174u,
        0xe49b69c1u,0xefbe4786u,0x0fc19dc6u,0x240ca1ccu,0x2de92c6fu,0x4a7484aau,0x5cb0a9dcu,0x76f988dau,
        0x983e5152u,0xa831c66du,0xb00327c8u,0xbf597fc7u,0xc6e00bf3u,0xd5a79147u,0x06ca6351u,0x14292967u,
        0x27b70a85u,0x2e1b2138u,0x4d2c6dfcu,0x53380d13u,0x650a7354u,0x766a0abbu,0x81c2c92eu,0x92722c85u,
        0xa2bfe8a1u,0xa81a664bu,0xc24b8b70u,0xc76c51a3u,0xd192e819u,0xd6990624u,0xf40e3585u,0x106aa070u,
        0x19a4c116u,0x1e376c08u,0x2748774cu,0x34b0bcb5u,0x391c0cb3u,0x4ed8aa4au,0x5b9cca4fu,0x682e6ff3u,
        0x748f82eeu,0x78a5636fu,0x84c87814u,0x8cc70208u,0x90befffau,0xa4506cebu,0xbef9a3f7u,0xc67178f2u
    };
    std::vector<unsigned char> bytes(input.begin(), input.end());
    uint64 bitlen = (uint64)bytes.size() * 8ULL;
    bytes.push_back(0x80);
    while ((bytes.size() * 8ULL) % 512ULL != 448ULL) bytes.push_back(0x00);
    for (int i = 7; i >= 0; --i) {
        bytes.push_back(static_cast<unsigned char>((bitlen >> (i * 8)) & 0xFF));
    }
    uint32 H[8] = {
        0x6a09e667u,0xbb67ae85u,0x3c6ef372u,0xa54ff53au,
        0x510e527fu,0x9b05688cu,0x1f83d9abu,0x5be0cd19u
    };
    for (size_t chunk = 0; chunk < bytes.size(); chunk += 64) {
        uint32 W[64];
        for (int t = 0; t < 16; ++t) {
            W[t] = (uint32)bytes[chunk + t*4] << 24 | (uint32)bytes[chunk + t*4 + 1] << 16 |
                   (uint32)bytes[chunk + t*4 + 2] << 8 | (uint32)bytes[chunk + t*4 + 3];
        }
        for (int t = 16; t < 64; ++t) {
            W[t] = SSIG1(W[t-2]) + W[t-7] + SSIG0(W[t-15]) + W[t-16];
        }
        uint32 a = H[0], b = H[1], c = H[2], d = H[3];
        uint32 e = H[4], f = H[5], g = H[6], h = H[7];
        for (int t = 0; t < 64; ++t) {
            uint32 T1 = h + BSIG1(e) + Ch(e,f,g) + K[t] + W[t];
            uint32 T2 = BSIG0(a) + Maj(a,b,c);
            h = g; g = f; f = e; e = d + T1; d = c; c = b; b = a; a = T1 + T2;
        }
        H[0] += a; H[1] += b; H[2] += c; H[3] += d;
        H[4] += e; H[5] += f; H[6] += g; H[7] += h;
    }
    std::ostringstream oss;
    for (int i = 0; i < 8; ++i) {
        oss << std::hex << std::setw(8) << std::setfill('0') << (uint32)H[i];
    }
    return oss.str();
}
std::string now_time_str() {
    auto t = std::time(nullptr);
    char buf[64];
    std::strftime(buf, sizeof(buf), "%F %T", std::localtime(&t));
    return std::string(buf);
}
struct Event {
    int pid;
    std::string uid;
    std::string action;
    std::string resource;
    std::string timestamp;    std::string serialize() const {
        std::ostringstream oss;
        oss << "{"
            << "\"PID\":" << pid << ","
            << "\"UID\":\"" << uid << "\","
            << "\"Action\":\"" << action << "\","
            << "\"Resource\":\"" << resource << "\","
            << "\"Timestamp\":\"" << timestamp << "\""
            << "}";
        return oss.str();
    }
};
struct Block {
    int index;
    std::string timestamp;
    Event data;
    std::string prev_hash;
    std::string validator;
    std::string hash;
    std::string compute_hash() const {
        std::ostringstream oss;
        oss << index << "|" << timestamp << "|" << data.serialize() << "|" << prev_hash << "|" << validator;
        return sha256(oss.str());
    }
    std::string to_json() const {
        std::ostringstream oss;
        oss << "{"
            << "\"index\":" << index << ","
            << "\"timestamp\":\"" << timestamp << "\","
            << "\"data\":" << data.serialize() << ","
            << "\"prev_hash\":\"" << prev_hash << "\","
            << "\"validator\":\"" << validator << "\","
            << "\"hash\":\"" << hash << "\""
            << "}";
        return oss.str();
    }
};
class Blockchain {
public:
    Blockchain(const std::string& consensus_mode = "PoA")
      : consensus(consensus_mode) {
        create_genesis_block();
    }
    void create_genesis_block() {
        Event e;
        e.pid = 0; e.uid = "system"; e.action = "GENESIS"; e.resource = "none"; e.timestamp = now_time_str();
        Block g;
        g.index = 0; g.timestamp = e.timestamp; g.data = e; g.prev_hash = "0"; g.validator = "genesis";
        g.hash = g.compute_hash();
        chain.push_back(g);
    }
    Block* add_block(const Event& event) {
        Block nb;
        nb.index = static_cast<int>(chain.size());
        nb.timestamp = now_time_str();
        nb.data = event;
        nb.prev_hash = chain.back().hash;
        nb.validator = select_validator();
        nb.hash = nb.compute_hash();
        if (consensus_validate(nb, chain.back())) {
            chain.push_back(nb);
            return &chain.back();
        } else {
            return nullptr;
        }
    }
    bool verify_chain(bool verbose = true) const {
        for (size_t i = 1; i < chain.size(); ++i) {
            const Block &cur = chain[i];
            const Block &prev = chain[i-1];
            if (cur.prev_hash != prev.hash) {
                if (verbose) std::cout << "Tampering detected at Block " << cur.index << " (prev_hash mismatch)!\n";
                return false;
            }
            if (cur.hash != cur.compute_hash()) {
                if (verbose) std::cout << "Data manipulation detected in Block " << cur.index << " (hash mismatch)!\n";
                return false;
            }
        }
        if (verbose) std::cout << "Blockchain verified: No tampering detected ✅\n";
        return true;
    }
    void export_hash_prefix_csv(const std::string &filename = "block_hash_prefix.csv") const {
        std::ofstream ofs(filename);
        if (!ofs) { std::cerr << "CSV export failed: cannot open " << filename << "\n"; return; }
        ofs << "index,hash_prefix_int\n";
        for (const auto &b : chain) {
            std::string prefix = b.hash.substr(0, 6); // first 6 hex chars
            unsigned int val = 0;
            std::istringstream iss(prefix);
            iss >> std::hex >> val;
            ofs << b.index << "," << val << "\n";
        }
        ofs.close();
    }
    void export_full_chain_json(const std::string &filename = "blockchain_export.json") const {
        std::ofstream ofs(filename);
        if (!ofs) { std::cerr << "JSON export failed: cannot open " << filename << "\n"; return; }
        ofs << "[\n";
        for (size_t i = 0; i < chain.size(); ++i) {
            ofs << chain[i].to_json();
            if (i + 1 < chain.size()) ofs << ",\n";
            else ofs << "\n";
        }
        ofs << "]\n";
        ofs.close();
    }
    std::vector<Block>& get_chain() { return chain; }
private:
    std::vector<Block> chain;
    std::string consensus;
    std::string select_validator() {
        static const std::vector<std::string> validators = { "PoA_Node1", "PoA_Node2", "PoA_Node3" };
        static std::mt19937 rng((unsigned)std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> dist(0, (int)validators.size() - 1);
        return validators[dist(rng)];
    }
    bool consensus_validate(const Block& new_block, const Block&) {
        if (consensus == "PoA") {
            return true;
        } else if (consensus == "PBFT") {
            static std::mt19937 rng((unsigned)std::chrono::system_clock::now().time_since_epoch().count());
            std::bernoulli_distribution vote(0.90);
            int yes = 0;
            for (int i = 0; i < 3; ++i) if (vote(rng)) ++yes;
            return yes >= 2;
        } else {
            return false;
        }
    }
};
Event generate_event(int pid) {
    static const std::vector<std::string> actions = {
        "CREATE_PROCESS", "TERMINATE_PROCESS", "OPEN_FILE", "PRIV_ESCALATION", "NETWORK_ACCESS"
    };
    static const std::vector<std::string> resources = {
        "/bin/bash", "/etc/passwd", "/var/log/syslog", "/usr/bin/python3", "TCP:8080"
    };
    static std::mt19937 rng((unsigned)std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> ia(0, (int)actions.size() - 1);
    std::uniform_int_distribution<int> ir(0, (int)resources.size() - 1);
    std::uniform_int_distribution<int> iu(1, 3);
    Event e;
    e.pid = pid;
    e.uid = "user" + std::to_string(iu(rng));
    e.action = actions[ia(rng)];
    e.resource = resources[ir(rng)];
    e.timestamp = now_time_str();
    return e;
}
void print_usage(const char* prog) {
    std::cout << "Usage: " << prog << " [consensus] [num_events] [tamper_index]\n";
    std::cout << "  consensus     : PoA (default) or PBFT\n";
    std::cout << "  num_events    : number of simulated OS events to generate (default 10)\n";
    std::cout << "  tamper_index  : (optional) index of block to tamper (>=1). Use -1 for no tamper (default).\n";
    std::cout << "Example: " << prog << " PBFT 12 3\n";
}
int main(int argc, char* argv[]) {
    std::string consensus = "PoA";
    int num_events = 10;
    int tamper_index = -1;
    if (argc >= 2) consensus = std::string(argv[1]);
    if (argc >= 3) num_events = std::max(1, std::atoi(argv[2]));
    if (argc >= 4) tamper_index = std::atoi(argv[3]);
    std::cout << "=== Blockchain-Backed OS Auditing Prototype ===\n";
    std::cout << "Consensus: " << consensus << " | Events: " << num_events
              << " | Tamper index: " << tamper_index << "\n\n";
    if (consensus != "PoA" && consensus != "PBFT") {
        std::cerr << "Error: consensus must be PoA or PBFT\n";
        print_usage(argv[0]);
        return 1;
    }
    Blockchain bc(consensus);
    for (int i = 0; i < num_events; ++i) {
        int pid = 1001 + i;
        Event ev = generate_event(pid);
        Block* added = bc.add_block(ev);
        if (added) {
            std::cout << "Block " << added->index << " added by " << added->validator
                      << " | hash: " << added->hash.substr(0, 16) << "...\n";
        } else {
            std::cout << "Block for PID " << pid << " rejected by consensus\n";
        }
    }
    std::cout << "\nInitial verification:\n";
    bc.verify_chain();
    if (tamper_index >= 1 && tamper_index < (int)bc.get_chain().size()) {
        std::cout << "\n--- Tampering Simulation ---\n";
        std::cout << "Modifying data in block " << tamper_index << " (but NOT recomputing its hash) ...\n";
        bc.get_chain()[tamper_index].data.action = "MODIFIED_ACTION_BY_ATTACKER";
    } else if (tamper_index >= (int)bc.get_chain().size()) {
        std::cout << "Tamper index out of range (no tampering performed).\n";
    }
    std::cout << "\nVerification after tampering (if any):\n";
    bc.verify_chain();
    bc.export_hash_prefix_csv("block_hash_prefix.csv");
    bc.export_full_chain_json("blockchain_export.json");
    std::cout << "\nExports written:\n - block_hash_prefix.csv\n - blockchain_export.json\n";
    std::cout << "\nDone. Use the JSON file for report screenshots and CSV for visual plots.\n";
    return 0;
}
