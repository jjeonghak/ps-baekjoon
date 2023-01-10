import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {

	private static int INF = -100_000_001;
	private static int n, m;
	private static int[] dx = {0, 0, 1};
	private static int[] dy = {1, -1, 0};

	private static int[][] cost;
	private static int[][] pathCost;
	private static int[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		cost = new int[n][m];
		pathCost = new int[m][2];
		dp = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				cost[i][j] = Integer.parseInt(st.nextToken());
				if (i == 0) {
					if (j == 0)
						dp[i][j] = cost[i][j];
					else
						dp[i][j] = dp[i][j - 1] + cost[i][j];
				}
			}
		}
		for (int i = 1; i < n; i++) {
			pathCost[0][0] = dp[i - 1][0] + cost[i][0];
			for (int j = 1; j < m; j++)
				pathCost[j][0] = Math.max(pathCost[j - 1][0], dp[i - 1][j]) + cost[i][j];
			pathCost[m - 1][1] = dp[i - 1][m - 1] + cost[i][m - 1];
			for (int j = m - 2; j >= 0; j--)
				pathCost[j][1] = Math.max(pathCost[j + 1][1], dp[i - 1][j]) + cost[i][j];
			for (int j = 0; j < m; j++)
				dp[i][j] = Math.max(pathCost[j][0], pathCost[j][1]);
		}
		bw.write(String.valueOf(dp[n - 1][m - 1]));
		bw.flush();
		bw.close();
		br.close();
	}
}
