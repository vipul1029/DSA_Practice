#include <iostream>
using namespace std;
void printValue(int x){
    x=x+10;
    cout<<"updated x:"<<x<<endl;
}
int main(){
    int x=5;
   printValue(x);
   //real value not updated
   cout<<"original x:"<<x;
    return 0;
}