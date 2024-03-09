import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] dp;
    static int[] coin;
    static int n, k;
    static final int INF = 10001;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        dp = new int[k + 1];
        coin = new int[n];
        for (int i=0; i<n; i++)
            coin[i] = Integer.parseInt(br.readLine());
        int ans = dfs(0);
        if (ans >= INF)
            System.out.println(-1);
        else
            System.out.println(ans);
    }

    static int dfs(int sum) {
        if (sum > k)
            return INF;
        else if (sum == k)
            return 0;
        else if (dp[sum] != 0)
            return dp[sum];
        dp[sum] = INF;
        for (int i=0; i<n; i++)
            dp[sum] = Math.min(dp[sum], dfs(sum + coin[i]) + 1);
        return dp[sum];
    }
}
