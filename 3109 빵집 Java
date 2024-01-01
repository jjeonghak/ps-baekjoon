import java.io.*;
import java.util.*;

class Main {

	private static int r, c;
	private static int[] dx = {-1, 0, 1};
	private static char[][] map;
	private static boolean[][] visit;
	private static int result;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		String[] input = br.readLine().split(" ");
		r = Integer.parseInt(input[0]);
		c = Integer.parseInt(input[1]);
		map = new char[r][c];
		visit = new boolean[r][c];

		for (int i = 0; i < r; i++) {
			map[i] = br.readLine().toCharArray();
		}

		for (int i = 0; i < r; i++) {
			dfs(i, 0);
		}

		sb.append(result);
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static boolean dfs(int x, int y) {
		if (y == c - 1) {
			result++;
			return true;
		}

		boolean success;

		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + 1;

			if (nx >= 0 && nx < r && !visit[nx][ny] && map[nx][ny] == '.') {
				visit[nx][ny] = true;
				success = dfs(nx, ny);
				if (success) {
					return true;
				}
			}
		}

		return false;
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
