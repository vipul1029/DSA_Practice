// Write a Program to Calculate the Greatest Common Divisor of Two Numbers
#include <iostream>
using namespace std;
int comciv(int a,int b){
    int result=min(a,b);
    for(int i=result;i>0;i--){
        if(a%i==0 && b%i==0){
            return i;
            break;

        }
          
    }
  
}
int main(){
    int a,b;
    cout<<"enter 2 number";
    cin>>a>>b;
    cout<<comciv(a,b);
    return 0;
}