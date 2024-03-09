import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static final int INF = 2100000000;
    static int totalFlag, n, p;
    static int[][] cost;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        cost = new int[n][n];
        for (int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j<n; j++)
                cost[i][j] = Integer.parseInt(st.nextToken());
        }
        char[] initFlag = br.readLine().toCharArray();
        int flag = 0;
        totalFlag = 0;
        for (int i=0; i<n; i++) {
            totalFlag |= 1 << i;
            if (initFlag[i] == 'Y')
                flag |= 1 << i;
        }
        dp = new int[totalFlag + 1];
        for (int i=0; i<totalFlag+1; i++)
            dp[i] = INF;
        p = Integer.parseInt(br.readLine());
        int result = dfs(flag);
        if (result >= INF)
            bw.write("-1");
        else
            bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
        br.close();
    }

    private static int dfs(int flag) {
        if (cntBit(flag) >= p)
            return 0;
        if (dp[flag] != INF)
            return dp[flag];
        for (int i=0; i<n; i++) {
            if ((flag & (1 << i)) == 0) {
                int costMin = INF;
                for (int j=0; j<n; j++) {
                    if ((flag & (1 << j)) > 0)
                        costMin = Math.min(costMin, cost[j][i]);
                }
                dp[flag] = Math.min(dp[flag], dfs(flag | (1 << i)) + costMin);
            }
        }
        return dp[flag];
    }

    private static int cntBit(int flag) {
        int cnt = 0;
        while (flag > 0) {
            cnt += flag % 2;
            flag >>= 1;
        }
        return cnt;
    }
}
