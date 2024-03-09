import java.io.*;
import java.util.*;
import java.util.stream.*;

class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		String[] input = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]);
		int k = Integer.parseInt(input[1]);

		Queue<Integer> queue = Stream
			.iterate(1, i -> i + 1)
			.limit(n)
			.collect(Collectors.toCollection(LinkedList::new));

		sb.append("<");
		while (!queue.isEmpty()) {
			for (int i = 0; i < k - 1; i++) {
				Integer index = queue.poll();
				queue.offer(index);
			}
			Integer index = queue.poll();
			sb.append(String.valueOf(index));
			if (!queue.isEmpty()) {
				sb.append(", ");
			}
		}
		sb.append(">");
		bw.write(sb.toString());
		bw.close();
		br.close();
	}
}
