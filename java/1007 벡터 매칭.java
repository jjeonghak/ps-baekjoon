import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {

	private static int n;
	private static boolean[] check;
	private static Node[] nodes;
	private static double ans;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			n = Integer.parseInt(br.readLine());
			check = new boolean[n];
			nodes = new Node[n];
			ans = Double.MAX_VALUE;
			for (int j = 0; j < n; j++) {
				String[] input = br.readLine().split(" ");
				nodes[j] = new Node(Integer.parseInt(input[0]),
					Integer.parseInt(input[1]));
			}
			combination(0, n / 2);
			bw.write(ans + "\n");
		}
		bw.flush();
		bw.close();
		br.close();
	}

	private static void combination(int index, int cnt) {
		if (cnt == 0) {
			double result = calVector();
			ans = Math.min(result, ans);
		} else {
			for (int i = index; i < n; i++) {
				check[i] = true;
				combination(i + 1, cnt - 1);
				check[i] = false;
			}
		}
	}

	private static double calVector() {
		int x = 0;
		int y = 0;
		for (int i = 0; i < n; i++) {
			if (check[i]) {
				x += nodes[i].x;
				y += nodes[i].y;
			} else {
				x -= nodes[i].x;
				y -= nodes[i].y;
			}
		}
		return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
	}

	private static class Node {
		int x;
		int y;

		public Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}
