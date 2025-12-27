#include <iostream>
using namespace std;
int sum(int a, int b){
    int c=a+b;
return c;
}
int main(){
    int x,y;
    cout<<"enter 2 number";
    cin>>x>>y;
    int result=sum(x,y);
    cout<<result;\
    return 0;
}