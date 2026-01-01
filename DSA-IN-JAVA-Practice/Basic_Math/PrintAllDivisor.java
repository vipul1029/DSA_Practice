import java.util.*;
public class PrintAllDivisor {
public static void main(String args[]){
    System.out.print("Enter a number: ");
    Scanner sc=new Scanner(System.in);
    int number=sc.nextInt();
    for(int i=2;i<number;i++){
        if(number%i==0){
        System.out.print(i+" ");
        }
    }
    
}
}
