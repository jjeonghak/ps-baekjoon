import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {

	private static int MOD = 1_000_000_007;
	private static long[] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = Integer.parseInt(br.readLine());
		dp = new long[5001];
		dp[0] = 1;
		dp[2] = 1;
		for (int i = 0; i < t; i++) {
			int l = Integer.parseInt(br.readLine());
			for (int j = 2; j <= l; j += 2) {
				if (dp[j] != 0)
					continue;
				for (int k = 0; k < j; k += 2) {
					dp[j] += dp[k] * dp[j - k - 2];
					dp[j] %= MOD;
				}
			}
			bw.write(String.valueOf(dp[l]) + "\n");
		}
		bw.flush();
		bw.close();
		br.close();
	}
}
