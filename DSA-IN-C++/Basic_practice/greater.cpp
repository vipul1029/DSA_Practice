//2. Write a Program to Find the Greatest of the Three Numbers. 
#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<"greatest among these is :";
    if(a>b &&a>c){
        cout<<a;
    }
    else if(b>a &&a>c){
        cout<<b;
    }
    else if(c>b &&c>a){
        cout<<c;
    }
    return 0;
}