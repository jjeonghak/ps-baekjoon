import java.io.*;
import java.util.*;

public class Solution {

	private static Map<Integer, Map<Integer, Integer>> map;
	private static int n, m, s, e;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		map = new HashMap<>();
		for (int i = 1; i <= n; i++) {
			map.put(i, new HashMap<>());
		}

		int l = Integer.MAX_VALUE;
		int r = Integer.MIN_VALUE;

		for (int i = 0; i < m; i++) {
			input = br.readLine().split(" ");
			int a = Integer.parseInt(input[0]);
			int b = Integer.parseInt(input[1]);
			int c = Integer.parseInt(input[2]);

			l = Math.min(l, c);
			r = Math.max(r, c);
			Map<Integer, Integer> aMap = map.get(a);
			Map<Integer, Integer> bMap = map.get(b);
			aMap.put(b, Math.max(aMap.get(b) == null ? c : aMap.get(b) , c));
			bMap.put(a, Math.max(bMap.get(a) == null ? c : bMap.get(a), c));
		}
		input = br.readLine().split(" ");
		s = Integer.parseInt(input[0]);
		e = Integer.parseInt(input[1]);

		int answer = 0;
		while (l <= r) {
			int mid = (l + r) / 2;

			if (checkWeight(mid)) {
				answer = Math.max(answer, mid);
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		sb.append(answer);
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static boolean checkWeight(int weight) {
		Queue<Integer> q = new LinkedList<>();
		q.offer(s);

		boolean[] check = new boolean[n + 1];
		check[s] = true;

		while (!q.isEmpty()) {
			int cur = q.poll();

			if (cur == e) {
				return true;
			}

			Map<Integer, Integer> curMap = map.get(cur);
			for (Map.Entry<Integer, Integer> next : curMap.entrySet()) {
				int key = next.getKey();
				int value = next.getValue();
				if (value >= weight && !check[key]) {
					check[key] = true;
					q.offer(key);
				}
			}
		}
		return false;
	}

}
