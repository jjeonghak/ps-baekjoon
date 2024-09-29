import java.io.*;
import java.util.*;

public class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(br.readLine());
		int[] input = Arrays.stream(br.readLine().split(" "))
				.mapToInt(Integer::parseInt)
				.toArray();

		Arrays.sort(input);
		long answer = Long.MAX_VALUE;
		int[] indexList = new int[3];
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 2; j < n; j++) {
				int mid = binarySearch(i, j, input);
				long result = (long)input[i] + input[mid] + input[j];
				if (Math.abs(result) < answer) {
					answer = Math.abs(result);
					indexList[0] = i;
					indexList[1] = mid;
					indexList[2] = j;
				}
			}
		}

		sb.append(input[indexList[0]]).append(" ").append(input[indexList[1]]).append(" ").append(input[indexList[2]]);
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static int binarySearch(int l, int r, int[] input) {
		int lb = l + 1;
		int rb = r - 1;

		long resultSum = Long.MAX_VALUE;
		int result = rb;

		while (lb < rb) {
			int mid = (lb + rb) / 2;
			long sum = (long)input[l] + input[mid] + input[r];
			if (Math.abs(sum) < resultSum) {
				resultSum = Math.abs(sum);
				result = mid;
			}
			if (sum < 0) {
				lb = mid + 1;
			} else if (sum > 0) {
				rb = mid;
			} else {
				result = mid;
				break;
			}
		}
		return result;
	}

}
