import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {

	private static int INT_MAX = Integer.MAX_VALUE;
	private static char[] s;
	private static int palindromeCnt[];
	private static boolean[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		s = br.readLine().toCharArray();
		init();

		solution();
		bw.write(String.valueOf(palindromeCnt[s.length]));
		bw.flush();
		bw.close();
		br.close();
	}

	private static void init() {
		dp = new boolean[s.length + 1][s.length + 1];
		palindromeCnt = new int[s.length + 1];
		palindromeCnt[0] = 0;
		for (int i = 1; i <= s.length; i++) {
			palindromeCnt[i] = INT_MAX;
			for (int j = 1; j <= i; j++) {
				dp[j][i] = isPalindrome(j - 1, i - 1);
			}
		}
	}

	private static void solution() {
		for (int i = 1; i <= s.length; i++) {
			for (int j = 1; j <= i; j++) {
				if (dp[j][i])
					palindromeCnt[i] = Math.min(palindromeCnt[i], palindromeCnt[j - 1] + 1);
			}
		}
	}

	private static boolean isPalindrome(int le, int ri) {
		int range = (ri - le) / 2;

		for (int i = 0; i <= range; i++) {
			if (s[le + i] != s[ri - i])
				return false;
		}
		return true;
	}
}
