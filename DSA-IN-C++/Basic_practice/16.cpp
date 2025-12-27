//16. Write a Program to Check the Prime Number
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=2;i<n;i++){
     if(n%i!=0){
        cout<<"prime";
        break;
          i++;
     }
  
   
    }
    cout<<"not prime";
   
}