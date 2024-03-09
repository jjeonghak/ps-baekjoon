import java.io.*;
import java.util.*;

class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		String[] input = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]);
		int k = Integer.parseInt(input[1]);
		char[] target = br.readLine().toCharArray();

		Stack<Character> stack = new Stack<>();
		Stack<Character> result = new Stack<>();
		stack.push(target[0]);
		for (int i = 1; i < n; i++) {
			while (k > 0 && !stack.isEmpty() && stack.peek() < target[i]) {
				stack.pop();
				k--;
			}
			stack.push(target[i]);
		}

		while (k > 0) {
			k--;
			stack.pop();
		}

		while (!stack.isEmpty()) {
			result.push(stack.pop());
		}

		while (!result.isEmpty()) {
			sb.append(result.pop());
		}

		bw.write(sb.toString());
		bw.close();
		br.close();
	}
}
