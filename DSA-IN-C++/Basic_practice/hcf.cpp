//hcf
#include <iostream>
using namespace std;
int main(){
    int a,b,temp;
    cout<<"first number";
    cin>>a;
    cout<<"second number";
    cin>>b;
int c;
if(a>b){
   c=b;
}
else{
    c=a;
}
for(int i=1;i<=c;i++){
    if(a%i==0 && b%i==0){
        temp=i;
    }
}
cout<<"HCF of "<<a<<" and "<<b<<" is "<<temp;
return 0;
}