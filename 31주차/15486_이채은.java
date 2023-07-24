import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] T = new int[N+1];
        int[] P = new int[N+1];
        int[] dp = new int[N+1];
        for (int i=0; i<N; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            T[i] = Integer.parseInt(stk.nextToken());
            P[i] = Integer.parseInt(stk.nextToken());
        }
        
        int max = 0;
        for(int i=0; i<N+1; i++){
            if(max < dp[i]) max = dp[i];
            int cnt = i + T[i];
            if(cnt < N+1)
                dp[cnt] = Math.max(dp[cnt], max+P[i]);
        }
        System.out.println(max);
    }
}
