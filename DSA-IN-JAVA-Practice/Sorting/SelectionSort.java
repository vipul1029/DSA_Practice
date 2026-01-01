import java.util.*;

public class SelectionSort {

    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int size=sc.nextInt();
        int arr[]=new int [size];
        System.out.print("Enter the elements of array");
        for(int i=0;i<size;i++){
            arr[i]=sc.nextInt();
        }
for(int i=0;i<size-1;i++){
    int minIndex=i;
for(int j=i+1;j<size;j++){
if(arr[minIndex]>arr[j]){
    int temp=arr[minIndex];
    arr[minIndex]=arr[j];
    arr[j]=temp;
}

}
        }
        System.out.print("Sorted array is: ");
        for(int i=0;i<size;i++){
  System.out.print( arr[i]+" ");
        }
      
    }
}
    

    
    

