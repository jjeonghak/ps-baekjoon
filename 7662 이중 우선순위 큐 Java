import java.io.*;
import java.util.*;

class Main {

	private static String INSERT = "I";
	private static String DELETE = "D";
	private static String EMPTY = "EMPTY";
	private static PriorityQueue<Long> pq = new PriorityQueue<>();
	private static PriorityQueue<Long> rpq = new PriorityQueue<>();
	private static Map<Long, Integer> map = new LinkedHashMap<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			pq.clear();
			rpq.clear();
			map.clear();
			int n = Integer.parseInt(br.readLine());
			for (int j = 0; j < n; j++) {
				String[] input = br.readLine().split(" ");
				compute(input[0], Long.parseLong(input[1]));
			}
			sb.append(getStatus()).append("\n");
		}
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static void compute(String operator, long value) {
		if (operator.equals(INSERT)) {
			if (!map.containsKey(value)) {
				map.put(value, 1);
			} else {
				map.replace(value, map.get(value) + 1);
			}
			pq.offer(value);
			rpq.offer(-value);
		} else if (operator.equals(DELETE)) {
			if (value == -1) {
				while (!pq.isEmpty()) {
					Long key = pq.poll();
					if (map.get(key) != 0) {
						map.replace(key, map.get(key) - 1);
						break;
					}
				}
			} else {
				while (!rpq.isEmpty()) {
					Long key = -rpq.poll();
					if (map.get(key) != 0) {
						map.replace(key, map.get(key) - 1);
						break;
					}
				}
			}
		}
	}

	private static String getStatus() {
		StringBuilder sb = new StringBuilder();
		long min = Long.MAX_VALUE;
		long max = Long.MIN_VALUE;
		for (Map.Entry<Long, Integer> e : map.entrySet()) {
			long key = e.getKey();
			if (!e.getValue().equals(0)) {
				min = Math.min(key, min);
				max = Math.max(key, max);
			}
		}
		if (min == Long.MAX_VALUE)
			return EMPTY;
		return sb.append(max).append(" ").append(min).toString();
	}
}
