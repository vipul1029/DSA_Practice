#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=1;
    for(int i=1;a<=n;i++){
        for(int j=1;j<=i && a<=n;j++){
         cout<<a<<" ";
        a++;
        }
        cout<<endl;
        
    }
}