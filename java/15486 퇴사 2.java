import java.io.*;
import java.util.*;

class Main {

	private static int[] days;
	private static int[] costs;
	private static long[] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(br.readLine());
		days = new int[n];
		costs = new int[n];
		dp = new long[n + 1];
		for (int i = 0; i < n; i++) {
			String[] input = br.readLine().split(" ");
			days[i] = Integer.parseInt(input[0]);
			costs[i] = Integer.parseInt(input[1]);
			dp[i] = -1;
		}

		long max = 0;
		for (int i = 0; i <= n; i++) {
			max = Math.max(max, dp[i]);
			if (i == n) {
				break;
			}
			int day = i + days[i];
			if (day <= n) {
				dp[day] = Math.max(dp[day], max + costs[i]);
			}
		}
		sb.append(max);
		// sb.append(solution(0, 0, n));
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	// private static long solution(int index, long total, int n) {
	// 	if (index == n) {
	// 		return total;
	// 	}
	// 	if (dp[index] != -1) {
	// 		return dp[index];
	// 	}
	//
	// 	if (index + days[index] <= n) {
	// 		dp[index] = Math.max(dp[index], solution(index + days[index], total + costs[index], n));
	// 	}
	// 	dp[index]  = Math.max(dp[index], solution(index + 1, total, n));
	//
	// 	return dp[index];
	// }

}
