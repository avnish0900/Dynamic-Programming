import java.util.*;
import java.io.*;
class Main {
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int []dp=new int[n+1];
    System.out.println("Ways="+Ways(n,dp));
  }
  public static int Ways(int n,int []dp){
    if(n==0){
      return 1;
    }
    if(n<0){
      return 0;
    }
    if(dp[n]!=0){
      return dp[n];
    }
    int last1=Ways(n-1,dp);
    int last2=Ways(n-2,dp);
    int last3=Ways(n-3,dp);
    int last=last1+last2+last3;
    dp[n]=last;
    return last;
  }
}
