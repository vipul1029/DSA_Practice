#include <iostream>
using namespace std;
int age(int &age){
    age=age +5;
    cout<<"new age : "<<age<<endl;
    return 0;
}
int main(){
int ag =18;
age(ag);
cout<<"current age : "<<ag;
}