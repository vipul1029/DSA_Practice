//22. Write a Program for Finding the Roots of a Quadratic Equation
#include <iostream>
using namespace std;
void root(int a,int b, int c){
    if(a==0){
   cout<<"invalid";
    }
    int d=b*b -4*a*c;
    if(d>0){
        cout<<"rootes are different";
    }
}
int main(){
    int a,b,c;
    cout<<"write coeff of a,b,c";
    cin>>a>>b>>c;
    root(a,b,c);
    return 0;
}