import java.io.*;
import java.util.*;

class Main {

	private static List<Edge>[] map;
	private static int maxDistance;
	private static int maxNode;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(br.readLine());
		map = new List[n + 1];
		for (int i = 1; i <= n; i++) {
			map[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			String[] input = br.readLine().split(" ");
			int from = Integer.parseInt(input[0]);
			int to = Integer.parseInt(input[1]);
			int distance = Integer.parseInt(input[2]);
			map[from].add(new Edge(to, distance));
			map[to].add(new Edge(from, distance));
		}
		maxDistance = -1;

		dfs(1, 0, 0);
		dfs(maxNode, 0, 0);
		sb.append(maxDistance);
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static void dfs(int node, int previous, int distance) {
		if (distance > maxDistance) {
			maxDistance = distance;
			maxNode = node;
		}

		List<Edge> edges = map[node];
		for (Edge edge : edges) {
			if (edge.to != previous) {
				dfs(edge.to, node, distance + edge.distance);
			}
		}
	}

	private static class Edge {
		public int to;
		public int distance;

		public Edge(int to, int distance) {
			this.to = to;
			this.distance = distance;
		}

		public Edge(String to, String distance) {
			this.to = Integer.parseInt(to);
			this.distance = Integer.parseInt(distance);
		}
	}

}
