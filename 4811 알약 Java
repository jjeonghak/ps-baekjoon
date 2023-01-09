import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {

	private static int n;
	private static long[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(br.readLine());
		while (n != 0) {
			initDp();
			sb.append(solution(n, 0)).append("\n");
			n = Integer.parseInt(br.readLine());
		}
		bw.write(String.valueOf(sb));
		bw.close();
		br.close();
	}

	private static void initDp() {
		dp = new long[n + 1][n + 1];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				dp[i][j] = 1;
	}

	private static long solution(int w, int h) {
		if (dp[w][h] != 1)
			return dp[w][h];
		if (w == 0)
			return dp[w][h] = 1;
		if (h == 0)
			return dp[w][h] *= solution(w - 1, h + 1);
		return dp[w][h] *= solution(w, h - 1) + solution(w - 1, h + 1);
	}
}
