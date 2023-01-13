import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {

	private static int dp[][];
	private static int cost[][];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]);
		int t = Integer.parseInt(input[1]);
		dp = new int[n + 1][t + 1];
		cost = new int[n + 1][n + 1];
		for (int i = 1; i <= n; i++) {
			input = br.readLine().split(" ");
			cost[i][0] = Integer.parseInt(input[0]);
			cost[i][1] = Integer.parseInt(input[1]);
		}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= t; j++)
				dp[i][j] = -1;
		bw.write(String.valueOf(solution(n, t)));
		bw.flush();
		bw.close();
		br.close();
	}

	private static int solution(int index, int total) {
		if (dp[index][total] != -1)
			return dp[index][total];
		if (index == 0)
			return 0;
		if (cost[index][0] <= total)
			dp[index][total] = Math.max(dp[index][total],
				solution(index - 1, total - cost[index][0]) + cost[index][1]);
		return dp[index][total] = Math.max(dp[index][total],
			solution(index - 1, total));
	}
}
