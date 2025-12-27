//13. Write a Program to Find the Sum of the First N Natural Numbers
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0;
for (int i=0;i<=n;i++){
      sum=sum+i;
}
    cout<<sum;
}