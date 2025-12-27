//10. Write a Program to Remove the Vowels from a String
#include <iostream>
using namespace std;
int main() {
    string str="viapulkumarmehra";
    int j=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i'
            && str[i] != 'o' && str[i] != 'u'
            && str[i] != 'A' && str[i] != 'E'
            && str[i] != 'I' && str[i] != 'O'
            && str[i] != 'U'){
                //Copy the character from position i to position j in the same array (str), and then increase j.
        str[j++]=str[i];
        }
    }
    while (j<str.size()){
        str[j]='\0';
        j++;
    }
    cout<<str;
}