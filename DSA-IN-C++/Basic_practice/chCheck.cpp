//6. Write a Program to Print Check Whether a Character is an Alphabet or Not
#include <iostream>
#include <cctype>
using namespace std;
int main(){
    char ch;
    ch= 'a';
    if(isalpha(ch)){
        cout<<"it is a alphabet:"<<ch;
    }
    else{
        cout<<"not a alphabet";
    }
}