import java.io.*;

class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(br.readLine());
		int[] input = new int[n];
		int[] dp = new int[n];
		for (int i = 0; i < n; i++) {
			input[i] = Integer.parseInt(br.readLine());
			dp[i] = 1;
		}
		int max = Integer.MIN_VALUE;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (input[i] > input[j] && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					max = Math.max(max, dp[i]);
				}
			}
		}
		sb.append(n - max);
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

}
