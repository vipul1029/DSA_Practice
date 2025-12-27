import java.util.*;
class Count_Digit{
public static void main(String [] args){
    System.out.println("Enter a number: ");
    Scanner sc=new Scanner(System.in);

      int n=sc.nextInt();
      int count=0;
      while(n>0){
       n=n/10;
       count++;

      }
      System.out.println(count);
}
}