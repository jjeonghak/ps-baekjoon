import java.io.*;
import java.util.*;

class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		Map<String, Integer> map = new LinkedHashMap<>();
		for (int i = 0; i < n; i++) {
			String input = br.readLine();
			if (!map.containsKey(input)) {
				map.put(input, 1);
			} else {
				map.replace(input, map.get(input) + 1);
			}
		}
		Map.Entry<String, Integer> result = map.entrySet().stream()
			.max((prev, next) ->
				prev.getValue().compareTo(next.getValue()) == 0
					? next.getKey().compareTo(prev.getKey())
					: prev.getValue().compareTo(next.getValue())
			).get();
		bw.write(result.getKey());
		bw.close();
		br.close();
	}

}
