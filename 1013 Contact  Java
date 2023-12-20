import java.io.*;
import java.util.*;

class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		String regex = "(100+1+|01)+";
		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			String input = br.readLine();
			if (input.matches(regex)) {
				sb.append("YES\n");
			} else {
				sb.append("NO\n");
			}
		}

		bw.write(sb.toString());
		bw.close();
		br.close();
	}

}
