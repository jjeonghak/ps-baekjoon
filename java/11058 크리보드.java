import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {

	private static long[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		dp = new long[n + 2][3];
		dp[0][0] = 1;
		dp[1][0] = 2;
		dp[2][0] = 3;
		dp[2][1] = 1;
		for (int i = 3; i < n; i++) {
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 2][0];
			for (int j = 1; j < 4; j++)
				dp[i][2] = Math.max(dp[i][2], dp[i - j][1] * (j + 1));
			dp[i][0] = Math.max(dp[i][0], dp[i][2]);
		}
		bw.write(String.valueOf(dp[n - 1][0]));
		bw.flush();
		bw.close();
		br.close();
	}
}
