import java.util.*;
public class Palindrome {
    public static void main(String [] args){
        System.out.print("Enter the number");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int original=n;
        int reverse =0;
        while(n>0){
            int digit=n%10;
            reverse=reverse*10 + digit;
            n=n/10;
        }
        if(original==reverse){
            System.out.print("Palindrome");
        }
        else{
         System.out.print("Not a palifrome");   
        }
        }
    }

