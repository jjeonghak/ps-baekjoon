import java.io.*;
import java.util.*;

class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(br.readLine());
		Integer[] input = Arrays.stream(br.readLine().split(" "))
				.map(Integer::parseInt)
				.toArray(Integer[]::new);

		int[] dp = new int[n];
		int[] previousDp = new int[n];
		for (int i = 0; i < n; i++) {
			dp[i] = 1;
			previousDp[i] = i;
		}

		for (int i = 1; i < n; i++) {
			int result = dp[i];
			for (int j = 0; j < i; j++) {
				if (input[i] > input[j] && result < dp[j] + 1) {
					result = dp[j] + 1;
					previousDp[i] = j;
				}
			}
			dp[i] = result;
		}

		int max = Integer.MIN_VALUE;
		int iter = 0;
		for (int i = 0; i < n; i++) {
			if (max < dp[i]) {
				iter = i;
				max = dp[i];
			}
		}

		sb.append(dp[iter]).append("\n");
		Stack<Integer> stack = new Stack<>();
		while (previousDp[iter] != iter) {
			stack.push(input[iter]);
			iter = previousDp[iter];
		}
		stack.push(input[iter]);

		while(!stack.isEmpty()) {
			sb.append(stack.pop()).append(" ");
		}

		bw.write(sb.toString());

		bw.close();
		br.close();
	}

}
