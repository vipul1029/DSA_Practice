import java.util.Scanner;
public class Main{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        int temp1;
        int temp2;
        int sum1=0;
        int sum2=0;
        int d;
        int c;
        int x=a;
       int  y=b; //int t
    while (a>0){
        temp1=a%10;
        sum1=sum1+temp1;
       a=a-temp1;
        a=a/10;
    }
    while(b>0){
        temp2=b%10;
        sum2=sum2+temp2;
      b=b-temp2;
        b=b/10;
    }
    if(sum1%2==0){
        d=x;
    }
    else{
        d=x*2;
    }
    if(sum2%2==0){
        c=y;
    }
    else{
        c=y*2;
    }
   int f=c*d;
    System.out.println(f);
    sc.close();
    }
}

