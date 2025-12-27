//binary search
#include <iostream>
using namespace std;
int main(){
    int key,n;
    cout<<"enter size of array:";
    cin>>n;
    int size=n-1;
   int arr[n];
    cout<<"enter array in ascending order:";
    for(int i=0;i<n;i++){
        
        cin>>arr[i];
    }
    
     cout<<"enter key;";
    cin>>key;
    int start=0;
    int end=size-1;
   
    
    while(start<=end){
         int mid=start+(end-start)/2;
        if(arr[mid]==key){
            cout<<"found key at "<<mid;
            break;
        }
        else if(arr[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        
        }
        if(start>end){
            cout<<"key not found";
        };
      
    }
