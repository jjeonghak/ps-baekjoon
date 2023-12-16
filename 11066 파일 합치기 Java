import java.io.*;
import java.util.*;

class Main {

	private static Integer[] input;
	private static int[] sum;
	private static int[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(br.readLine());
			input = Arrays.stream(br.readLine().split(" "))
					.map(Integer::parseInt)
					.toArray(Integer[]::new);
			initDp(n);
			initSum(n);
			sb.append(solution(0, n - 1)).append("\n");
		}
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static void initDp(int n) {
		dp = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = Integer.MAX_VALUE;
			}
		}
	}

	private static void initSum(int n) {
		sum = new int[n];
		sum[0] = input[0];
		for (int i = 1; i < n; i++) {
			sum[i] += sum[i - 1] + input[i];
		}

	}

	private static int solution(int lb, int rb) {
		if (dp[lb][rb] != Integer.MAX_VALUE) {
			return dp[lb][rb];
		}
		if (lb == rb) {
			return 0;
		}

		for (int i = lb; i < rb; i++) {
			int lbResult = solution(lb, i);
			int rbResult = solution(i + 1, rb);
			int total = lb != 0 ? sum[rb] - sum[lb - 1] : sum[rb];
			dp[lb][rb] = Math.min(dp[lb][rb], lbResult + rbResult + total);
		}
		return dp[lb][rb];
	}

}
