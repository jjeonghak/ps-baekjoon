import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class Main {

	private static List<Integer> input;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(br.readLine());
		input = Arrays.stream(br.readLine().split(" "))
				.map(Integer::parseInt)
				.sorted()
				.collect(Collectors.toList());

		int result = 0;
		for (int i = 0; i < n; i++) {
			int lb = 0;
			int rb = n - 1;

			while (lb < rb) {
				if (lb == i) {
					lb++;
				} else if (rb == i) {
					rb--;
				}

				if (lb >= rb) {
					break;
				}

				if (input.get(lb) + input.get(rb) > input.get(i)) {
					rb--;
				} else if (input.get(lb) + input.get(rb) < input.get(i)) {
					lb++;
				} else {
					result++;
					break;
				}
			}
		}

		sb.append(result);
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

}
