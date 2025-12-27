#include <iostream>
using namespace std;

int main(){
    int n,count=0;
    cout<<"Enter the number:";
    cin>>n;
    while(n>0){
        n=n/10;
       int temp=n;
        temp=n%10;
        cout<<"Digits: "<<temp<<endl;
        count++;
    }
    cout<<"Total number of digits: "<<count<<endl;
    return 0;
}