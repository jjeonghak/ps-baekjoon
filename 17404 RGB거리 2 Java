import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {

	private static int INF = 1_000_001;
	private static int n;
	private static int[][] cost;
	private static int[][][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		n = Integer.parseInt(br.readLine());
		cost = new int[n][3];
		dp = new int[n][3][3];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 3; j++) {
				cost[i][j] = Integer.parseInt(st.nextToken());
				for (int k = 0; k < 3; k++)
					dp[i][j][k] = INF;
			}
		}
		int ans = INF;
		for (int i = 0; i < 3; i++) {
			ans = Math.min(ans, solution(0, i, i));
		}
		bw.write(String.valueOf(ans));
		bw.flush();
		bw.close();
		br.close();
	}

	private static int solution(int index, int color, int firstColor) {
		if (index == n - 1) {
			if (color == firstColor)
				return dp[index][color][firstColor] = INF;
			else
				return dp[index][color][firstColor] = cost[index][color];
		}
		if (dp[index][color][firstColor] != INF)
			return dp[index][color][firstColor];
		return dp[index][color][firstColor] = Math.min(
			solution(index + 1, (color + 1) % 3, firstColor) + cost[index][color],
			solution(index + 1, (color + 2) % 3, firstColor) + cost[index][color]);
	}
}
