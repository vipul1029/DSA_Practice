// Name-vipul kumar Reg no.- 23BCE0572
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char name[20];
    char type[10];
    int size;
    int location;
} Symbol;

Symbol table[MAX];
int count = 0;
int next_location = 0;

int getSize(char type[]) {
    if (strcmp(type, "int") == 0)
        return 4;
    else if (strcmp(type, "float") == 0)
        return 4;
    else if (strcmp(type, "char") == 0)
        return 1;
    else if (strcmp(type, "double") == 0)
        return 8;
    return 0;
}

void insert(char name[], char type[]) {
    if (strlen(name) == 0 || strlen(type) == 0)
        return;

    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Error: Duplicate variable '%s'\n", name);
            return;
        }
    }

    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    table[count].size = getSize(type);
    table[count].location = next_location;
    next_location += table[count].size;
    count++;
}

void display() {
    printf("\n%-10s %-12s %-10s %-8s\n", "Location", "Identifier", "Datatype", "Size");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-12s %-10s %-8d\n",
               table[i].location,
               table[i].name,
               table[i].type,
               table[i].size);
    }
}

int main() {
    char code[200];
    printf("Enter code: ");
    fgets(code, sizeof(code), stdin);

    char *token = strtok(code, " ,;\n");
    char currentType[10] = "";

    while (token != NULL) {
        if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 ||
            strcmp(token, "char") == 0 || strcmp(token, "double") == 0) {
            strcpy(currentType, token);
        } else {
            insert(token, currentType);
        }
        token = strtok(NULL, " ,;\n");
    }

    display();
    return 0;
}