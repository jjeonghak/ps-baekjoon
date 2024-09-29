import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine());
		int n = Integer.parseInt(br.readLine());
		List<Integer> aTotalSub = Arrays.stream(br.readLine().split(" "))
				.map(Integer::parseInt)
				.collect(Collectors.toList());

		int m = Integer.parseInt(br.readLine());
		List<Integer> bTotalSub = Arrays.stream(br.readLine().split(" "))
				.map(Integer::parseInt)
				.collect(Collectors.toList());

		List<Integer> aSubSum = getSubSums(aTotalSub, n);
		List<Integer> bSubSum = getSubSums(bTotalSub, m);

		Map<Integer, Long> aMap = aSubSum.stream()
				.collect(Collectors.groupingBy(e -> e, Collectors.counting()));

		long answer = 0;
		for (int bSub : bSubSum) {
			int complement = T - bSub;
			if (aMap.containsKey(complement)) {
				answer += aMap.get(complement);
			}
		}

		bw.write(Long.toString(answer));
		bw.close();
		br.close();
	}

	private static List<Integer> getSubSums(List<Integer> arr, int size) {
		List<Integer> subSums = new ArrayList<>();
		for (int i = 0; i < size; i++) {
			int sum = 0;
			for (int j = i; j < size; j++) {
				sum += arr.get(j);
				subSums.add(sum);
			}
		}
		return subSums;
	}

}
