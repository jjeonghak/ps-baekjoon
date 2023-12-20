import java.io.*;
import java.util.*;

class Main {

	private static String result;
	private static boolean[] check;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			String[] input = br.readLine().split(" ");
			int a = Integer.parseInt(input[0]);
			int b = Integer.parseInt(input[1]);
			check = new boolean[10000];
			bfs(a, b);
			sb.append(result).append("\n");
		}

		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static void bfs(int a, int b) {
		Queue<Node> queue = new LinkedList();
		queue.offer(new Node(a, new StringBuilder()));
		while (!queue.isEmpty()) {
			Node node = queue.poll();

			if (node.current == b) {
				result = node.operations.toString();
				break;
			}

			int resultD = operD(node.current);
			if (!check[resultD]) {
				check[resultD] = true;
				queue.offer(new Node(resultD, new StringBuilder(node.operations).append("D")));
			}

			int resultS = operS(node.current);
			if (!check[resultS]) {
				check[resultS] = true;
				queue.offer(new Node(resultS, new StringBuilder(node.operations).append("S")));
			}

			int resultL = operL(node.current);
			if (!check[resultL]) {
				check[resultL] = true;
				queue.offer(new Node(resultL, new StringBuilder(node.operations).append("L")));
			}

			int resultR = operR(node.current);
			if (!check[resultR]) {
				check[resultR] = true;
				queue.offer(new Node(resultR, new StringBuilder(node.operations).append("R")));
			}
		}
	}

	private static int operD(int target) {
		return target * 2 % 10000;

	}

	private static int operS(int target) {
		return target != 0 ? target - 1 : 9999;
	}

	private static int operL(int target) {
		return target % 1000 * 10 + target / 1000;
	}

	private static int operR(int target) {
		return target / 10 + target % 10 * 1000;
	}

	private static class Node {
		public int current;
		public StringBuilder operations;

		public Node(int current, StringBuilder operations) {
			this.current = current;
			this.operations = operations;
		}
	}

}
