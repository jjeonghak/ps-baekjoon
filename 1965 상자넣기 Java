import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

class Main {

	private static int[] arr;
	private static int[] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		arr = new int[n];
		dp = new int[n];
		String[] input = br.readLine().split(" ");
		for (int i = 0; i < n; i++)
			arr[i] = Integer.parseInt(input[i]);
		Arrays.fill(dp, 1);
		for (int i = 0; i < n; i++) {
			int dpMax = 1;
			for (int j = 0; j < i; j++) {
				if (arr[j] < arr[i] && dpMax < dp[j] + 1)
					dpMax = dp[j] + 1;
			}
			dp[i] = dpMax;
		}
		bw.write(String.valueOf(Arrays.stream(dp).max().getAsInt()));
		bw.flush();
		bw.close();
		br.close();
	}
}
