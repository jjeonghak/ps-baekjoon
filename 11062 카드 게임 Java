import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] card;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t != 0) {
            t--;
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            card = new int[n];
            dp = new int[n][n];
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    dp[i][j] = -1;
            st = new StringTokenizer(br.readLine());
            for (int i=0; i<n; i++)
                card[i] = Integer.parseInt(st.nextToken());
            dfs(0, n - 1, true);
            sb.append(dp[0][n - 1]).append("\n");
        }
        System.out.println(sb);
        br.close();
    }

    static int dfs(int l, int r, boolean f) {
        if(l > r)
            return 0;
        else if (dp[l][r] != -1)
            return dp[l][r];
        if (f)
            dp[l][r] = Math.max(dfs(l + 1, r, false) + card[l],
                    dfs(l, r -1, false) + card[r]);
        else
            dp[l][r] = Math.min(dfs(l + 1, r, true), dfs(l, r -1, true));
        return dp[l][r];
    }
}
