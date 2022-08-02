import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n % 2 != 0) {
            System.out.println(0);
        } else {
            dp = new int[n + 1];
            for (int i = 1; i <= n; i++)
                dp[i] = -1;
            dp[0] = 1;
            dp[2] = 3;
            System.out.println(dfs(n));
        }
    }

    static int dfs(int n) {
        if (dp[n] != -1)
            return dp[n];
        dp[n] = 0;
        for (int i=2; i<=n; i+=2) {
            if (i == 2)
                dp[n] += dfs(n - i) * dp[2];
            else
                dp[n] += dfs(n - i) * 2;
        }
        return dp[n];
    }
}
