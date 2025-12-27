//8 Write a Program to Toggle Each Character in a String 
#include <iostream>
using namespace std;
int main() {
    string ch="viPulMeHra";
    for(int i=0;ch[i]!='\0';i++){
        if(islower(ch[i])){
          ch[i]=toupper(ch[i]);
        }
        else if(isupper(ch[i])){
            ch[i]=tolower(ch[i]);
        }
    }
    cout<<ch;
}