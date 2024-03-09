import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

class Main {

	private static int p, q;
	private static long[] dp;
	private static Map<Long, Integer> mapping = new HashMap<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		long n = Long.parseLong(input[0]);
		p = Integer.parseInt(input[1]);
		q = Integer.parseInt(input[2]);
		initMap(n);
		initDp();
		long ans = 1;
		if (n >= 1)
			ans = solution(n);
		bw.write(String.valueOf(ans));
		bw.flush();
		bw.close();
		br.close();
	}

	private static void initMap(long n) {
		int sequence = 0;
		Queue<Long> queue = new LinkedList<>();
		queue.offer(n);
		mapping.put(n, sequence++);
		while (!queue.isEmpty()) {
			long i = queue.poll();
			if (!mapping.containsKey(i / p)) {
				queue.offer(i / p);
				mapping.put(i / p, sequence++);
			}
			if (!mapping.containsKey(i / q)) {
				queue.offer(i / q);
				mapping.put(i / q, sequence++);
			}
		}
	}

	private static void initDp() {
		dp = new long[mapping.size()];
		for (int i = 0; i < mapping.size(); i++)
			dp[i] = -1;
	}

	private static long solution(long i) {
		if (i == 0)
			return 1;
		int index = mapping.get(i);
		if (dp[index] != -1)
			return dp[index];
		return dp[index] = solution(i / p) + solution(i / q);
	}
}
