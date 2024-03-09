import java.io.*;
import java.util.*;

class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(input[0]);
		int m = Integer.parseInt(input[1]);
		Map<String, String> map = new HashMap<>();
		for (int i = 0; i < n; i++) {
			String[] inputString = br.readLine().split(" ");
			map.put(inputString[0], inputString[1]);
		}
		for (int i = 0; i < m; i++) {
			String site = br.readLine();
			sb.append(map.get(site)).append("\n");
		}
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

}
