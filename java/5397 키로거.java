import java.io.*;

class Main {

	private static StringBuilder prefix;
	private static StringBuilder suffix;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());

		for (int i = 0; i < n; i++) {
			char[] input = br.readLine().toCharArray();
			init();
			for (char c : input) {
				if (c == '<' || c == '>') {
					move(c);
				} else if (c == '-') {
					delete();
				} else {
					add(c);
				}
			}
			sb.append(prefix).append(suffix.reverse()).append("\n");
		}
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static void init() {
		prefix = new StringBuilder();
		suffix = new StringBuilder();
	}

	private static void move(char c) {
		if (c == '<') {
			if (prefix.length() != 0) {
				suffix.append(prefix.charAt(prefix.length() - 1));
				prefix.deleteCharAt(prefix.length() - 1);
			}
		} else {
			if (suffix.length() != 0) {
				prefix.append(suffix.charAt(suffix.length() - 1));
				suffix.deleteCharAt(suffix.length() - 1);
			}
		}
	}

	private static void delete() {
		if (prefix.length() != 0) {
			prefix.deleteCharAt(prefix.length() - 1);
		}
	}

	private static void add(char c) {
		prefix.append(c);
	}

}
