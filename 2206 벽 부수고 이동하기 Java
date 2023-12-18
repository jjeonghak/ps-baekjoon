import java.io.*;
import java.util.*;

class Main {

	private static int n, m;
	private static int[][] map;
	private static boolean[][][] visit;
	private static int[] dx = { 0, 0, 1, -1 };
	private static int[] dy = { 1, -1, 0, 0 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		map = new int[n][m];
		visit = new boolean[n][m][2];
		for (int i = 0; i < n; i++) {
			char[] line = br.readLine().toCharArray();
			for (int j = 0; j < m; j++) {
				map[i][j] = Character.getNumericValue(line[j]);
			}
		}
		sb.append(bfs());
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static int bfs() {
		Queue<Node> queue = new LinkedList<>();
		queue.offer(new Node(0, 0, 1, 1));
		int result = -1;
		while (!queue.isEmpty()) {
			Node node = queue.poll();

			if (node.x == n - 1 && node.y == m - 1) {
				result = node.distance;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny][node.broken]) {
					if (map[nx][ny] == 0) {
						queue.offer(new Node(nx, ny, node.distance + 1, node.broken));
						visit[nx][ny][node.broken] = true;
					} else if (map[nx][ny] == 1 && node.broken == 1) {
						queue.offer(new Node(nx, ny, node.distance + 1, 0));
						visit[nx][ny][0] = true;
					}
				}
			}
		}
		return result;
	}

	private static class Node {
		public int x;
		public int y;
		public int distance;
		public int broken;

		public Node(int x, int y, int distance, int broken) {
			this.x = x;
			this.y = y;
			this.distance = distance;
			this.broken = broken;
		}
	}

}
