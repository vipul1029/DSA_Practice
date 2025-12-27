//first and last occurance of a number in and sorted array
#include <iostream>
using namespace std;
int main(){
    int n,key;
    cout<<"enter size of array";
    cin>>n;
  
    int arr[n];
    cout<<"enter array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter key number:";
    cin>>key;
    int size=n-1;
    int start=0;
    int end = size;
     int last=-1;
        int first=-1;
    while(start<=end)
{
    int mid=start+(end-start)/2;
    if(arr[mid]==key){
        first=mid;
        last=mid;
       
    while(arr[mid+1]==key){
        mid++;
         last=mid;
    }
    
 
    while(arr[mid-1]==key){
        mid--;
        first=mid;
    }
  
    break;
    }
    else if(arr[mid]<key){
     end =mid-1;
    }
    else{
   start=mid+1;
    }
}  
if(start>end){
    cout<<"not found";

} 
else{
    cout<<"first occurance is at"<<first;
    cout<<"last occurance is at"<<last;
    
}
return 0;
}
