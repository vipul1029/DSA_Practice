//21. Write a Program to Calculate the Lowest Common Multiple (LCM) of Two Numbers
#include <iostream>
using namespace std;
int lcm(int a,int b){
    int result=max(a,b);
    for (int i=result;;i++){
        if(i%a==0 &&i%b==0){
            return i;
            break;
        }
    }
}
int main(){
    int a,b;
    cout<<"enter 2 number";
    cin>>a>>b;
    cout<<lcm(a,b);
    return 0;
}