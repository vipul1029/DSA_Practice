import java.util.*;
public class ArmstrongNumber {
   
    void  Armstrong(int n){
         int sum =0;
         int original =n;
         while(n>0){
            int digit=n%10;
            sum=sum +digit*digit*digit;
            n=n/10;
         }
         if(original==sum){
            System.out.print("Armstrong Number");
         }
         else{
            System.out.print("Not a Armstrong Number");
         }
    }
    public static void main(String [] args){
    System.out.print("Enter your number:");
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    ArmstrongNumber obj=new ArmstrongNumber();
    obj.Armstrong(n);
    
    }
}
