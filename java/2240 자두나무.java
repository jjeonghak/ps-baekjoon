import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {

	private static int t, w;
	private static int[] map = new int[1000];
	private static int[][][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());

		t = Integer.parseInt(st.nextToken());
		w = Integer.parseInt(st.nextToken());

		dp = new int[2][w + 1][t];
		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			map[i] = Integer.parseInt(st.nextToken());
		}

		initDp();
		int ans = Math.max(calMax(0, w, 0), calMax(0, w - 1, 1));
		bw.write(String.valueOf(ans));

		bw.flush();
		bw.close();
		br.close();
	}

	private static void initDp() {
		for (int i = 0; i < w + 1; i++) {
			for (int j = 0; j < t; j++) {
				dp[0][i][j] = -1;
				dp[1][i][j] = -1;
			}
		}
	}

	private static int calMax(int current, int cnt, int state) {
		if (current == t)
			return 0;
		if (dp[state][cnt][current] != -1)
			return dp[state][cnt][current];
		if (cnt > 0)
			dp[state][cnt][current] = Math.max(calMax(current + 1, cnt, state),
				calMax(current + 1, cnt - 1, (state + 1) % 2));
		else
			dp[state][cnt][current] = calMax(current + 1, cnt, state);
		if (map[current] == state + 1)
			dp[state][cnt][current] += 1;
		return dp[state][cnt][current];
	}
}
