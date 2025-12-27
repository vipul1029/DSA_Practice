//to reverse a integer
#include<iostream>
using namespace std;
int main (){
    int a;
    cout<<"enter a number";
    cin>>a;
int ans=0; 
    while(a!=0){
     
    //  b=a%10;
    //  a=a/10;
    //  cout<<b;
     int digit=a%10;
     //if((ans>INT_MAX/10)||(ans<INT_MIN/10)){cout<<"overflow"; return 0;}
   ans=ans*10+digit;
   a=a/10;
   
    }
    cout<<ans;
}
// else{
//     cout<<"-";
//      while(a<0){
//      int b;
//      b=a%10;
//      a=a/10;
//      cout<<(-b);
//     //  int ans=0;
// //      int digit=a%10;   
// //    ans=ans*10-digit;
// //    a=a/10;
// //    cout<<ans;
//     }

