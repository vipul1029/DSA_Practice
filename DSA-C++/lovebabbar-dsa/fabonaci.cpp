#include <iostream>
using namespace std;
int main(){
    int a=0;
    int b=1;
    int n;
    int sum;
    cin>>n;
    for(int i=0;i<=n;i++){
        if(i==0){
            cout<<a<<" "<<b<< " ";
        }
        if(i>0){
        sum=a +b;
        cout<<sum<<" ";
        a=b;
        b=sum;
        }
        
    }
}