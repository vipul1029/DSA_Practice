//15. Write a Program to Find a Leap Year or Not
#include <iostream>
using namespace std;
int main(){
    int year;
    cin>>year;
        if(year%4==0){
            if(year%100!=0){
                cout<<"It is a leap year";
            }
        }
    else{
        cout<<"It is a non leap year";
    }
}