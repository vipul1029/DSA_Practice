//between number is prime or not
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int temp=0;
    for(int i=2;i<=n;i++){
        bool isPrime=true;
    for(int j=2;j<i;j++){
    if(i%j==0){
        // cout<<i<<" "<<"not prime"<<endl;
        isPrime=false;
        break;
    
    }

}
if(isPrime){
    cout<<i<<" "<<"not prime"<<endl;
}
else{
    cout<<i<<" "<<"prime"<<endl;
    break;
}
 

}
if(n==1 ||n==0){
    cout<<n<<" "<<"prime"<<endl;
}
}