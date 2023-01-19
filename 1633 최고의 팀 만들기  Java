import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {

	private static int n;
	private static int[][] member;
	private static int[][][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		member = new int[1000][1000];
		while (true) {
			String input = br.readLine();
			if (input == null || input.isEmpty() || input.equals("\n"))
				break;
			String[] memberCapacity = input.split(" ");
			member[n][0] = Integer.parseInt(memberCapacity[0]);
			member[n][1] = Integer.parseInt(memberCapacity[1]);
			n++;
		}
		dp = new int[n][16][16];
		bw.write(String.valueOf(solution(0, 0, 0)));
		bw.flush();
		bw.close();
		br.close();
	}

	private static int solution(int index, int w, int b) {
		if (w == 15 && b == 15)
			return 0;
		if (index == n)
			return 0;
		if (dp[index][w][b] != 0)
			return dp[index][w][b];
		int ans = solution(index + 1, w, b);
		if (w < 15)
			ans = Math.max(ans, solution(index + 1, w + 1, b) + member[index][0]);
		if (b < 15)
			ans = Math.max(ans, solution(index + 1, w, b + 1) + member[index][1]);
		return dp[index][w][b] = ans;
	}
}
