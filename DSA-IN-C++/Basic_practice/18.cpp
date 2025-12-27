//18. Write a Program to Check Whether a Number is an Armstrong Number or Not
#include <iostream>
using namespace std;
int main(){
    int n=153;
    int ans=0;
    int temp=n; 
    while(n>0){
    int rem=n%10;
    ans=ans+rem*rem*rem;
    n=n/10;
    }
if(temp==ans){
    cout<<"it is a amastrong number";
}else{
    cout<<"it is not a amastrong";
}
return 0;
}