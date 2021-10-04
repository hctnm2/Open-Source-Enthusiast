import java.io.*;
import java.util.*;

public class Main {

    static int[] dp;

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; ++i) {
            arr[i] = sc.nextInt();
        }
        dp = new int[n+1];
        
        System.out.println(climbVar(n, arr));
    }
    
    public static int climbVar(int n, int[] arr) {
        dp[n] = 1;
        
        for(int i = n-1; i >= 0; --i) {
            for(int j = 1; j <= arr[i] && j+i <= n; ++j) {
                dp[i] += dp[i+j];
            }
        }
        
        return dp[0];
    }

}
