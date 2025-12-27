import java.util.*;
 class Reverce_Number {
    public static void main(String []args){
        System.out.print("Enter your number:");
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        int reverse=0;
        while(n>0){
            int digit=n%10;
            reverse=reverse*10+digit;
            n=n/10;
        }
        System.out.print("Reversed: "+ reverse);
    }
}
