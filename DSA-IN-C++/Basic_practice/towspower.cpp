//if a number is in the form of 2^x or none
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n>1){
        if(n%2==0){
            n=n/2;       
        }
        else if(n%2!=0){
           cout<<"false";  
           break;
        }
      }
      if(n==1){
        cout<<"true";
      }
      else if(n==0){
        cout<<"true";
      }
       return 0;
        }
       
