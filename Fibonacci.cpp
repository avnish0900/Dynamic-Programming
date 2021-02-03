import java.util.*;
import java.io.*;
class Main {
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int []dp=new int[n+1];
    System.out.println("fibo="+fibo(n,dp));
  }
  public static int fibo(int n,int []dp){
    if(n==0 || n==1){
      return n;
    }
    if(dp[n]!=0){
      return dp[n];
    }
    int last1=fibo(n-1,dp);
    int last2=fibo(n-2,dp);
    int last=last1+last2;
    dp[n]=last;
    return last;
  }
}
