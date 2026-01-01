import java.util.*;
public class CheckForpime {
    public static void main(String []args){
        System.out.print("enter your number");
        Scanner sc=new Scanner(System.in);
        int number =sc.nextInt();
        boolean isprime=true;
        for(int i=2;i<number;i++){
            if(number%i==0){
                isprime=false;
                break;
            }
        }
        if(!isprime){
            System.out.print("This is not a prime number");
        }
        else{
            System.out.print("This is a prime number");
        }
    }
}
