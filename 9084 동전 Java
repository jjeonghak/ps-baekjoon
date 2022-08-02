import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static int[] dp;
    static int[] cost;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        int t = Integer.parseInt(br.readLine());
        while (t != 0) {
            t--;
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            cost = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i=0; i<n; i++)
                cost[i] = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(br.readLine());
            dp = new int[m + 1];
            solution();
            sb.append(dp[m]).append("\n");
        }
        System.out.println(sb);
    }

    static void solution() {
        dp[0] = 1;
        for (int i=0; i<n; i++) {
            for (int j=cost[i]; j<=m; j++) {
                dp[j] += dp[j - cost[i]];
            }
        }
    }
}
