//19. Write a Program to Find the Nth Term of the Fibonacci Series
#include <iostream>
using namespace std;
    int fab(int n){
        int first=0;
        int second=1;
        int ans;
        if (n==0){
            return first;}
            for(int i=2;i<=n;i++){
                ans =first+second;
                first=second;
                second=ans; 
            }
            return ans;
        
    }
    int main(){
        int n;
        cout<<"enter number";
        cin >>n;
      
        cout<<fab(n);
    }
