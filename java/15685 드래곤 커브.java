import java.io.*;
import java.util.*;

class Solution {

	private static int[] dx = {1, 0, -1, 0};
	private static int[] dy = {0, -1, 0, 1};
	private static boolean[][] map = new boolean[101][101];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			String[] input = br.readLine().split(" ");
			int x = Integer.parseInt(input[0]);
			int y = Integer.parseInt(input[1]);
			int d = Integer.parseInt(input[2]);
			int g = Integer.parseInt(input[3]);
			generateCurve(x, y, d, g);
		}

		int answer = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (checkLocation(i, j)) {
					answer++;
				}
			}
		}


		sb.append(answer);
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static void generateCurve(int x, int y, int d, int g) {
		List<Integer> directions = new ArrayList<>();
		directions.add(d);
		for (int i = 1; i <= g; i++) {
			int size = directions.size();
			for (int j = size - 1; j >= 0; j--) {
				directions.add((directions.get(j) + 1) % 4);
			}
		}

		map[x][y] = true;
		for (int dir :  directions) {
			x += dx[dir];
			y += dy[dir];
			map[x][y] = true;
		}
	}

	private static boolean checkLocation(int x, int y) {
		int nx = x + 1;
		int ny = y + 1;

		return map[x][y] && map[x][ny] && map[nx][y] && map[nx][ny];
	}

}
