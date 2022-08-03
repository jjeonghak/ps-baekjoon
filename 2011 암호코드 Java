import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int n;
    static int[] dp;
    static char[] s;
    static boolean check;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s = br.readLine().toCharArray();
        n = s.length;
        dp = new int[n];
        for (int i=0; i<n; i++)
            dp[i] = -1;
        if (check || s[0] == '0')
            System.out.println(0);
        else
            System.out.println(dfs(n - 1));
    }

    static int dfs(int len) {
        if (len < 0)
            return 1;
        else if (len == 0)
            return dp[0] = 1;
        else if (dp[len] != -1)
            return dp[len];
        dp[len] = 0;
        if (s[len] != '0')
            dp[len] += dfs(len - 1) % 1000000;
        if (s[len - 1] == '1' || (s[len - 1] == '2' && s[len] < '7')) {
            dp[len] += dfs(len - 2) % 1000000;
        } else if (s[len] == '0') {
            check = true;
        }
        return dp[len] %= 1000000;
    }
}
