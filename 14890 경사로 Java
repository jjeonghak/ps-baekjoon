import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

class Main {

	private static int n, l;
	private static int[][] map;

	private enum Road {
		RAW {
			public List<Integer> calRoadLength(int index) {
				List<Integer> loadLengths = new ArrayList<>();
				int length = 1;
				for (int i = 1; i < n; i++) {
					if (map[index][i - 1] != map[index][i]) {
						loadLengths.add(length);
						length = 1;
					} else {
						length += 1;
					}
					if (i == n - 1)
						loadLengths.add(length);
				}
				return loadLengths;
			}

			public List<Integer> calRoadHeight(int index) {
				List<Integer> loadHeights = new ArrayList<>();
				int height = map[index][0];
				for (int i = 1; i < n; i++) {
					if (map[index][i - 1] != map[index][i]) {
						loadHeights.add(height);
						height = map[index][i];
					}
					if (i == n - 1)
						loadHeights.add(height);
				}
				return loadHeights;
			}
		},
		COLUMN {
			public List<Integer> calRoadLength(int index) {
				List<Integer> loadLengths = new ArrayList<>();
				int length = 1;
				for (int i = 1; i < n; i++) {
					if (map[i - 1][index] != map[i][index]) {
						loadLengths.add(length);
						length = 1;
					} else {
						length += 1;
					}
					if (i == n - 1)
						loadLengths.add(length);
				}
				return loadLengths;
			}

			public List<Integer> calRoadHeight(int index) {
				List<Integer> loadHeights = new ArrayList<>();
				int height = map[0][index];
				for (int i = 1; i < n; i++) {
					if (map[i - 1][index] != map[i][index]) {
						loadHeights.add(height);
						height = map[i][index];
					}
					if (i == n - 1)
						loadHeights.add(height);
				}
				return loadHeights;
			}
		};
		
		public abstract List<Integer> calRoadLength(int index);
		public abstract List<Integer> calRoadHeight(int index);

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		l = Integer.parseInt(input[1]);
		map = new int[n][n];
		for (int i = 0; i < n; i++) {
			input = br.readLine().split(" ");
			for (int j = 0; j < n; j++)
				map[i][j] = Integer.parseInt(input[j]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (isRightRoad(i, Road.RAW))
				ans += 1;
			if (isRightRoad(i, Road.COLUMN))
				ans += 1;
		}
		bw.write(String.valueOf(ans));
		bw.flush();
		bw.close();
		br.close();
	}

	private static boolean isRightRoad(int index, Road road) {
		List<Integer> roadLengths = road.calRoadLength(index);
		List<Integer> roadHeights = road.calRoadHeight(index);
		for (int i = 0; i < roadLengths.size() - 1; i++) {
			int diff = roadHeights.get(i) - roadHeights.get(i + 1);
			if (diff == -1) {
				if (roadLengths.get(i) < l)
					return false;
				roadLengths.set(i, roadLengths.get(i) - l);
			} else if (diff == 1) {
				if (roadLengths.get(i + 1) < l)
					return false;
				roadLengths.set(i + 1, roadLengths.get(i + 1) - l);
			} else {
				return false;
			}
		}
		return true;
	}
}
