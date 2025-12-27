//7. Write a Program to Find the Length of the String Without using strlen() Function 
#include <iostream>
using namespace std;
int main() {
    string a="vipul kumar";
    int length=0;
  for (int i=0;a[i]!='\0';i++){
    length++;
  }
  cout<<length;
}