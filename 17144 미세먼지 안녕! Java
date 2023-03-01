import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {

	private static final int[] dx = {0, 1, 0, -1};
	private static final int[] dy = {1, 0, -1, 0};
	private static int r, c, t;
	private static int r1, r2;
 	private static int[][] map;
	private static int[][] lazy;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		r = Integer.parseInt(input[0]);
		c = Integer.parseInt(input[1]);
		t = Integer.parseInt(input[2]);
		map = new int[r][c];
		lazy = new int[r][c];
		for (int i = 0; i < r; i++) {
			input = br.readLine().split(" ");
			for (int j = 0; j < c; j++) {
				map[i][j] = Integer.parseInt(input[j]);
				if (map[i][j] == -1 && r1 == 0) {
					r1 = i;
					r2 = i + 1;
				}
			}
		}
		bw.write(String.valueOf(solution()));
		bw.flush();
		bw.close();
		br.close();
	}

	private static int solution() {
		int result = 0;
		while (t != 0) {
			propagation();
			operation();
			t -= 1;
		}
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				result += map[i][j];
		return result + 2;
	}

	private static void operation() {
		for (int i = 2; i < c; i++) {
			lazy[r1][i] += map[r1][i - 1];
			lazy[r2][i] += map[r2][i - 1];
			lazy[r1][i - 1] -= map[r1][i - 1];
			lazy[r2][i - 1] -= map[r2][i - 1];
		}
		for (int i = 0; i < c - 1; i++) {
			lazy[0][i] += map[0][i + 1];
			lazy[r - 1][i] += map[r - 1][i + 1];
			lazy[0][i + 1] -= map[0][i + 1];
			lazy[r - 1][i + 1] -= map[r - 1][i + 1];
		}
		for (int i = 0; i < r1; i++) {
			lazy[i][c - 1] += map[i + 1][c - 1];
			lazy[r1 - i][0] += map[r1 - i - 1][0];
			lazy[i + 1][c - 1] -= map[i + 1][c - 1];
			lazy[r1 - i - 1][0] -= map[r1 - i - 1][0];
		}
		for (int i = r - 1; i > r2; i--) {
			lazy[i][c - 1] += map[i - 1][c - 1];
			lazy[i - 1][c - 1] -= map[i - 1][c - 1];
		}
		for (int i = r2; i < r - 1; i++) {
			lazy[i][0] += map[i + 1][0];
			lazy[i + 1][0] -= map[i + 1][0];
		}
		patch();
	}

	private static void propagation() {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] >= 5) {
					int quantity = map[i][j] / 5;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx >= 0 && nx < r && ny >= 0 && ny < c
							&& map[nx][ny] != -1) {
							lazy[nx][ny] += quantity;
							lazy[i][j] -= quantity;
						}
					}
				}
			}
		}
		patch();
	}

	private static void patch() {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] != -1)
					map[i][j] += lazy[i][j];
				lazy[i][j] = 0;
			}
		}
	}
}
