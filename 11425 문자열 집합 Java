import java.io.*;
import java.util.*;

class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]);
		int m = Integer.parseInt(input[1]);
		List<String> strings = new ArrayList<>();
		List<String> targets = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			targets.add(br.readLine());
		}
		for (int i = 0; i < m; i++) {
			strings.add(br.readLine());
		}
		long answer = strings.stream()
			.filter(targets::contains)
			.count();
		bw.write(String.valueOf(answer));
		bw.close();
		br.close();
	}

}
