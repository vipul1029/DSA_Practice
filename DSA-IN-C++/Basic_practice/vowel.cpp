//5. Write a Program to Check Whether a Character is a Vowel or Consonant
#include <iostream>
#include <cctype>
using namespace std;
int main(){
    char ch;
    cin>>ch;
    if(isalpha(ch)){
    if(ch=='a' || ch=='e' ||ch=='i' ||ch=='o' ||ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
cout<<"it is Vowel";
}
else{
    cout<<"consonent";
}}
else{
    cout<<"not a alphabet";
return 0;
}
}