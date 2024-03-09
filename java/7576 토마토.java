import java.io.*;
import java.util.*;

class Main {

	private static int[][] map;
	private static int[] dx = { 0, 0, 1, -1 };
	private static int[] dy = { 1, -1, 0, 0 };
	private static Queue<Node> queue = new LinkedList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		String[] input = br.readLine().split(" ");
		int m = Integer.parseInt(input[0]);
		int n = Integer.parseInt(input[1]);
		int empty = 0;
		map = new int[n][m];

		for (int i = 0; i < n; i++) {
			input = br.readLine().split(" ");
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(input[j]);
				if (map[i][j] == 1) {
					queue.offer(new Node(i, j, 0));
				} else if (map[i][j] == -1) {
					empty++;
				}
			}
		}
		sb.append(bfs(n, m, empty));
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static int bfs(int n, int m, int empty) {
		int cnt = 0;
		int depthMax = -1;
		while (!queue.isEmpty()) {
			Node node = queue.poll();
			cnt++;
			depthMax = Math.max(depthMax, node.depth);

			for (int i = 0; i < 4; i++) {
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 0) {
					map[nx][ny] = 1;
					queue.offer(new Node(nx, ny, node.depth + 1));
				}
			}
		}
		if (cnt != m * n - empty) {
			depthMax = -1;
		}
		return depthMax;
	}

	private static class Node {
		public int x;
		public int y;
		public int depth;

		public Node(int x, int y, int depth) {
			this.x = x;
			this.y = y;
			this.depth = depth;
		}
	}

}
