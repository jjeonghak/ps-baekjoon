import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

class Main {

	private static int n;
	private static int[][] map;
	private static long[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		dp = new long[n][n];
		for (int i = 0; i < n; i++) {
			String[] input = br.readLine().split(" ");
			for (int j = 0; j < n; j++)
				map[i][j] = Integer.parseInt(input[j]);
		}
		for (int i = 0; i < n; i++)
			Arrays.fill(dp[i], -1);
		dp[n - 1][n - 1] = 1;
		bw.write(String.valueOf(solution(0, 0)));
		bw.flush();
		bw.close();
		br.close();
	}

	private static long solution(int x, int y) {
		if (dp[x][y] != -1)
			return dp[x][y];
		if (map[x][y] == 0)
			return dp[x][y] = 0;
		dp[x][y] = 0;
		int nx = x + map[x][y];
		int ny = y + map[x][y];
		if (nx < n)
			dp[x][y] += solution(nx, y);
		if (ny < n)
			dp[x][y] += solution(x, ny);
		return dp[x][y];
	}
}
