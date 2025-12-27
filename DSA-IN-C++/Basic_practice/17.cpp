//17. Write a Program to Check Palindrome
#include <iostream>
using namespace std;
bool ispalindron(string str){
    int start=0;
    int end =str.length()-1;
    while(start<end){
        if(str[start]!=str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main() {
   string input;
   cout<<"type string";
   cin>>input;
   if(ispalindron(input)){
    cout<<"it is a palidrime";
   }else{
    cout<<"it is not a palindrome";
   }
}