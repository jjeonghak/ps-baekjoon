import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Vector;

class Main {

	private static int n;
	private static Vector<Node>[] path;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		int q = Integer.parseInt(input[1]);
		path = new Vector[n + 1];
		for (int i = 0; i < n + 1; i++)
			path[i] = new Vector<>();
		for (int i = 0; i < n - 1; i++) {
			input = br.readLine().split(" ");
			int a = Integer.parseInt(input[0]);
			int b = Integer.parseInt(input[1]);
			int c = Integer.parseInt(input[2]);
			path[a].add(new Node(b, c));
			path[b].add(new Node(a, c));
		}
		for (int i = 0; i < q; i++) {
			input = br.readLine().split(" ");
			int k = Integer.parseInt(input[0]);
			int v = Integer.parseInt(input[1]);
			bw.write(solution(k, v) + "\n");
		}
		bw.flush();
		bw.close();
		br.close();
	}

	private static int solution(int usado, int index) {
		int ans = 0;
		Queue<Integer> q = new LinkedList<>();
		q.add(index);
		boolean[] check = new boolean[n + 1];
		Arrays.fill(check, false);
		check[index] = true;
		while (!q.isEmpty()) {
			Integer frontIndex = q.poll();
			for (int i = 0; i < path[frontIndex].size(); i++) {
				Node node = path[frontIndex].get(i);
				if (!check[node.index] && usado <= node.usado) {
					check[node.index] = true;
					q.add(node.index);
					ans += 1;
				}
			}
		}
		return ans;
	}

	private static class Node {
		int index;
		int usado;

		public Node(int index, int usado) {
			this.index = index;
			this.usado = usado;
		}
	}
}
