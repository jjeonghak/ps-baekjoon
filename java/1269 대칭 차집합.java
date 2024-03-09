import java.io.*;
import java.util.*;
import java.util.stream.*;

class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		int a = Integer.parseInt(input[0]);
		int b = Integer.parseInt(input[1]);
		Set<String> aIndexs = Arrays.stream(br.readLine().split(" ")).collect(Collectors.toSet());
		Set<String> bIndexs = Arrays.stream(br.readLine().split(" ")).collect(Collectors.toSet());

		long aCnt = aIndexs.stream()
			.filter(s -> !bIndexs.contains(s))
			.count();
		long bCnt = bIndexs.stream()
			.filter(s -> !aIndexs.contains(s))
			.count();

		bw.write(String.valueOf(aCnt + bCnt));
		bw.close();
		br.close();
	}

}
