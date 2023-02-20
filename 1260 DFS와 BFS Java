import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

class Main {

	private static int n, m, v;
	private static List<Integer>[] node;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		v = Integer.parseInt(input[2]);
		node = new List[n + 1];
		for (int i = 0; i < n + 1; i++)
			node[i] = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			input = br.readLine().split(" ");
			int a = Integer.parseInt(input[0]);
			int b = Integer.parseInt(input[1]);
			node[a].add(b);
			node[b].add(a);
		}
		for (int i = 0; i < n + 1; i++)
			Collections.sort(node[i]);
		bw.write(dfs() + "\n");
		bw.write(bfs());
		bw.flush();
		bw.close();
		br.close();
	}

	private static String dfs() {
		StringBuilder sb = new StringBuilder();
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		boolean[] check = new boolean[n + 1];
		Arrays.fill(check, false);
		pq.add(new Pair(0, v));
		while (!pq.isEmpty()) {
			Pair current = pq.poll();
			if (!check[current.index])
				check[current.index] = true;
			else
				continue;
			sb.append(current.index + " ");
			for (int i = 0; i < node[current.index].size(); i++) {
				int nextChild = node[current.index].get(i);
				if (!check[nextChild]) {
					pq.add(new Pair(current.depth + 1, nextChild));
				}
			}
		}
		return sb.toString();
	}

	private static String bfs() {
		StringBuilder sb = new StringBuilder();
		Queue<Integer> q = new LinkedList<>();
		boolean[] check = new boolean[n + 1];
		Arrays.fill(check, false);
		q.add(v);
		check[v] = true;
		while (!q.isEmpty()) {
			int current = q.poll();
			sb.append(current + " ");
			for (int i = 0; i < node[current].size(); i++) {
				int nextChild = node[current].get(i);
				if (!check[nextChild]) {
					q.add(nextChild);
					check[nextChild] = true;
				}
			}
		}
		return sb.toString();
	}

	private static class Pair implements Comparable<Pair> {
		public int depth;
		public int index;

		public Pair(int depth, int index) {
			this.depth = depth;
			this.index = index;
		}

		@Override
		public int compareTo(Pair o) {
				return this.depth != o.depth
					? o.depth - this.depth
					: this.index - o.index;
		}
	}
}
