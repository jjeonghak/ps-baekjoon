import java.io.*;
import java.util.*;

class Main {

	private static int n, m, result;
	private static int[] dx = {0, 0, -1, 1};
	private static int[] dy = {-1, 1, 0, 0};
	private static char[][] map;
	private static boolean[][] visit;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		result = Integer.MIN_VALUE;
		map = new char[n][m];

		for (int i = 0; i < n; i++) {
			map[i] = br.readLine().toCharArray();
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 'L') {
					bfs(i, j);
				}
			}
		}

		sb.append(result);
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static void bfs(int x, int y) {
		Queue<Node> queue = new LinkedList<>();
		queue.offer(new Node(x, y, 0));
		visit = new boolean[n][m];
		visit[x][y] = true;

		while (!queue.isEmpty()) {
			Node node = queue.poll();
			result = Math.max(result, node.depth);

			for (int i = 0; i < 4; i++) {
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] == 'L') {
					queue.offer(new Node(nx, ny, node.depth + 1));
					visit[nx][ny] = true;
				}
			}
		}
	}

	private static class Node {
		private int x;
		private int y;
		private int depth;

		public Node(int x, int y, int depth) {
			this.x = x;
			this.y = y;
			this.depth = depth;
		}
	}

}
