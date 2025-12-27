#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i;
    int a=1;
    for( i=1;a<=n;i++){
         a=i;
        for(int j=1;j<=i;j++) {
            
            cout<<a<<" ";
            a++;
        }  
    cout<<endl;
    }
}