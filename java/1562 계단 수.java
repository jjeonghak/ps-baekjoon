import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {

	private static int MOD = 1_000_000_000;
	private static int CHECK_FLAG = (1 << 10) - 1;
	private static int n;
	private static long[][][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		n = Integer.parseInt(br.readLine());
		long ans = 0;
		if (n >= 10) {
			initDp();
			for (int i = 1; i < 10; i++)
				ans += solution(i, n, (1 << i)) % MOD;
		}
		bw.write(String.valueOf(ans % MOD));
		bw.flush();
		bw.close();
		br.close();
	}

	private static void initDp() {
		dp = new long[10][n + 1][CHECK_FLAG + 1];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k <= CHECK_FLAG; k++) {
					if (j == 1) {
						if (k == CHECK_FLAG)
							dp[i][j][k] = 1;
						else
							dp[i][j][k] = 0;
					}
					else
						dp[i][j][k] = -1;
				}
			}
		}
	}

	private static long solution(int index, int cnt, int flag) {
		if (dp[index][cnt][flag] != -1)
			return dp[index][cnt][flag];
		if (index == 0)
			return dp[0][cnt][flag] = solution(1, cnt - 1, flag | (1 << 1)) % MOD;
		if (index == 9)
			return dp[9][cnt][flag] = solution(8, cnt - 1, flag | (1 << 8)) % MOD;
		return dp[index][cnt][flag] = (solution(index - 1, cnt - 1, flag | (1 << (index - 1)))
			+ solution(index + 1, cnt - 1, flag | (1 << (index + 1)))) % MOD;
	}
}
