import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

	private static int INF = 21474846;
	private static int c, n;
	private static int[] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		c = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		dp = new int[c + 101];
		Arrays.fill(dp, INF);
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int cost = Integer.parseInt(st.nextToken());
			int cnt = Integer.parseInt(st.nextToken());
			for (int j = cnt; j < c + 101; j++)
				dp[j] = Math.min(dp[j], cost + dp[j - cnt]);
		}
		int ans = INF;
		for (int i = c; i < c + 101; i++)
			ans = Math.min(ans, dp[i]);
		bw.write(String.valueOf(ans));
		bw.flush();
		bw.close();
		br.close();
	}
}
