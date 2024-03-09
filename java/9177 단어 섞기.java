import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {

	private static int firstLength, secondLength, thirdLength;
	private static int[][] dp;
	private static String[] dataSet;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());

		for (int i = 1; i <= n; i++) {
			dataSet = br.readLine().split(" ");
			firstLength = dataSet[0].length();
			secondLength = dataSet[1].length();
			thirdLength = dataSet[2].length();
			dp = new int[firstLength + 1][secondLength + 1];
			for (int j = 0; j <= firstLength; j++)
				for (int k = 0; k <= secondLength; k++)
					dp[j][k] = -1;
			printFormat(i, solution(0, 0));
		}
	}

	private static int solution(int f, int s) {
		if (f + s == thirdLength)
			return 1;
		if (dp[f][s] != -1)
			return dp[f][s];
		if (f < firstLength && dataSet[2].charAt(f + s) == dataSet[0].charAt(f)
			&& solution(f + 1, s) == 1)
			return dp[f][s] = 1;
		if (s < secondLength && dataSet[2].charAt(f + s) == dataSet[1].charAt(s)
			&& solution(f, s + 1) == 1)
			return dp[f][s] = 1;
		return dp[f][s] = 0;
	}

	private static void printFormat(int testCase, int ans) {
		String s;
		if (ans == 1)
			s = "yes";
		else
			s = "no";
		System.out.println("Data set " + testCase + ": " + s);
	}
}
