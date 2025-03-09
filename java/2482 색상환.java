import java.io.*;
import java.util.*;

public class Main {

    private static final int MOD = 1_000_000_003;
    private static int[][] dp;
    private static int n, k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());
        dp = new int[n][k + 1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        sb.append((solution(0, k) + solution(2, k - 1)) % MOD);
        bw.write(sb.toString());
        bw.close();
        br.close();
    }

    private static int solution(int index, int cnt) {
        if (cnt == 0) {
            return 1;
        }
        if (index >= n || n <= cnt + index) {
            return 0;
        }
        if (dp[index][cnt] != -1) {
            return dp[index][cnt];
        }
        int temp = 0;
        temp += solution(index + 1, cnt) % MOD;
        temp += solution(index + 2, cnt - 1) % MOD;
        dp[index][cnt] = temp % MOD;
        return dp[index][cnt];
    }
}
