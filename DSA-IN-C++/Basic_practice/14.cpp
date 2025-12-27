//14. Write a Program to Find the Factorial of a Number Using Loops
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=1;
    int fact=1;
    while(i<=n){
   fact*=i;
   i++;
    }
    cout<<fact;
}