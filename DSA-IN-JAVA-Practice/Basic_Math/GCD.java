import java.util.*;
public class GCD {
    int  gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
        }
    
    public static void main(String [] args){
        System.out.print("Entwr first number:");
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        System.out.print("Enter second number:");
        int b=sc.nextInt();
        GCD obj=new GCD();
        int result=obj.gcd(a,b);
        System.out.print("GCD is: "+ result);
    }
}
