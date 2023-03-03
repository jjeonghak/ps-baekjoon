import java.io.*;
import java.util.*;

class Main {

	private static int n;
	private static int[] map;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		n = Integer.parseInt(br.readLine());
		String[] input = br.readLine().split(" ");
		map = new int[n];
		for (int i = 0; i < n; i++)
			map[i] = Integer.parseInt(input[i]);
		Arrays.sort(map);
		long ans = 0;
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				ans += upper_bound(j + 1, n, -(map[i] + map[j]));
				ans -= lower_bound(j + 1, n, -(map[i] + map[j]));
			}
		}
		bw.write(String.valueOf(ans));
		bw.close();
		br.close();
	}

	private static long lower_bound(int l, int r, int target) {
		while (r > l) {
			int mid = (l + r) / 2;
			if (map[mid] >= target)
				r = mid;
			else
				l = mid + 1;
		}
		return r;
	}

	private static long upper_bound(int l, int r, int target) {
		while (r > l) {
			int mid = (l + r) / 2;
			if (map[mid] > target)
				r = mid;
			else
				l = mid + 1;
		}
		return r;
	}
}
