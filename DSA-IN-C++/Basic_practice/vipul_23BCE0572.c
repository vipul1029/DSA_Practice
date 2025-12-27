#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
typedef struct {
    char name[10];
    char type[10];
} Symbol;
Symbol table[MAX];
int count = 0;
char* getType(char* var) {
    for(int i = 0; i < count; i++) {
        if(strcmp(table[i].name, var) == 0) {
            return table[i].type;
        }
    }
    return NULL;
}
void checkStatement(char* stmt) {
    char lhs[10], rhs[100];
    int i = 0, j = 0;
    while(stmt[i] != '=' && stmt[i] != '\0') {
        if(stmt[i] != ' ') lhs[j++] = stmt[i];
        i++;
    }
    lhs[j] = '\0';
    if(stmt[i] == '\0') {
        printf("%s : ERROR - Invalid statement\n", stmt);
        return;
    }
    i++; 
    j = 0;
    while(stmt[i] != '\0') {
        if(stmt[i] != ' ' && stmt[i] != ';') rhs[j++] = stmt[i];
        i++;
    }
    rhs[j] = '\0';
    char* lhsType = getType(lhs);
    if(!lhsType) {
        printf("%s : ERROR - Variable '%s' not declared\n", stmt, lhs);
        return;
    }
    char variables[20][10];
    int varCount = 0;
    j = 0;
    for(i = 0; i <= strlen(rhs); i++) {
        if(isalpha(rhs[i])) {
            variables[varCount][j++] = rhs[i];
        } else {
            if(j > 0) {
                variables[varCount][j] = '\0';
                varCount++;
                j = 0;
            }
        }
    }
    int hasFloat = 0;
    for(i = 0; i < varCount; i++) {
        char* varType = getType(variables[i]);
        if(!varType) {
            printf("%s : ERROR - Variable '%s' not declared\n", stmt, variables[i]);
            return;
        }
        if(strcmp(varType, "float") == 0) {
            hasFloat = 1;
        }
    }
    char* resultType = hasFloat ? "float" : "int";
    printf("%s : ", stmt);
    if(strcmp(lhsType, resultType) == 0) {
        printf("Valid\n");
    } else if(strcmp(lhsType, "float") == 0 && strcmp(resultType, "int") == 0) {
        printf("Valid (int to float)\n");
    } else {
        printf("ERROR - Type mismatch (%s = %s)\n", lhsType, resultType);
    }
}
int main() {
    int n, stmts;
    char type[10], vars[50], stmt[100];
    printf("=== Universal Type Checking Program ===\n\n");\
    printf("Enter number of declaration lines: ");
    scanf("%d", &n);
    getchar();
    printf("\nEnter declarations (format: type var1,var2,...):\n");
    for(int i = 0; i < n; i++) {
        printf("Line %d: ", i+1);
        scanf("%s", type);
        fgets(vars, 50, stdin);
        char* token = strtok(vars, " ,;\n");
        while(token != NULL) {
            strcpy(table[count].name, token);
            strcpy(table[count].type, type);
            count++;
            token = strtok(NULL, " ,;\n");
        }
    }
    printf("\nSymbol Table:\n");
    for(int i = 0; i < count; i++) {
        printf("  %s : %s\n", table[i].name, table[i].type);
    }
    printf("\nEnter number of statements to check: ");
    scanf("%d", &stmts);
    getchar();
    printf("\nType Checking Results:\n");
    for(int i = 0; i < stmts; i++) {
        fgets(stmt, 100, stdin);
        stmt[strcspn(stmt, "\n")] = 0;
        checkStatement(stmt);
    }
    return 0;
}


