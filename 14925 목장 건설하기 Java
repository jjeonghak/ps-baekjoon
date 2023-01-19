import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

class Main {

	private static int m, n;
	private static int[][] map;

	private static int[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		m = Integer.parseInt(input[0]);
		n = Integer.parseInt(input[1]);
		dp = new int[m][n];
		map = new int[m][n];
		for (int i = 0; i < dp.length; i++)
			Arrays.fill(dp[i], -1);
		for (int i = 0; i < m; i++) {
			input = br.readLine().split(" ");
			for (int j = 0; j < n; j++)
				map[i][j] = Integer.parseInt(input[j]);
		}
		int ans = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				ans = Math.max(ans, solution(i, j));
		bw.write(String.valueOf(ans));
		bw.flush();
		bw.close();
		br.close();
	}

	private static int solution(int x, int y) {
		if (x >= m || y >= n)
			return 0;
		if (dp[x][y] != -1)
			return dp[x][y];
		if (map[x][y] != 0)
			return dp[x][y] = 0;
		int ans = solution(x + 1, y);
		ans = Math.min(ans, solution(x, y + 1));
		ans = Math.min(ans, solution(x + 1, y + 1));
		return dp[x][y] = ans + 1;
	}
}
