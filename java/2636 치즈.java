import java.io.*;
import java.util.*;

class Main {

	private static int n, m, result, previousResult;
	private static int[] dx = {0, 0, -1, 1};
	private static int[] dy = {-1, 1, 0, 0};
	private static int[][] map;
	private static boolean[][] visit;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		map = new int[n][m];
		visit = new boolean[n][m];

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			input = br.readLine().split(" ");
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(input[j]);
				cnt += map[i][j] == 1 ? 1 : 0;
			}
		}

		Queue<Node> queue = new LinkedList<>();
		queue.offer(new Node(0, 0));
		visit[0][0] = true;
		bfs(queue, 0, cnt);
		sb.append(result).append("\n").append(previousResult);
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static void bfs(Queue<Node> queue, int depth, int previous) {
		Queue<Node> next = new LinkedList<>();

		while (!queue.isEmpty()) {
			Node node = queue.poll();

			for (int i = 0; i < 4; i++) {
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny]) {
					if (map[nx][ny] == 1) {
						next.offer(new Node(nx, ny));
					} else {
						queue.offer(new Node(nx, ny));
					}
					visit[nx][ny] = true;
				}
			}
		}

		if (!next.isEmpty()) {
			previous = next.size();
			bfs(next, depth + 1, previous);
		} else {
			previousResult = previous;
			result = depth;
		}
	}

	private static class Node {
		private int x;
		private int y;

		public Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

}
