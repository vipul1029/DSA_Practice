//each letter of string are store in array
#include <iostream>
using namespace std;
int main(){
    string s;
    s="vipulKumar";
     s[7]='a';
     int len=s.size();
    cout<<s[5]<<s[6]<<s[len-1]<<endl;
    cout<<s;
}