import java.io.*;
import java.util.*;

class Main {

	private static List<Pair> lectures = new ArrayList<>();
	private static PriorityQueue<Integer> classrooms = new PriorityQueue<>();

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			String[] input = br.readLine().split(" ");
			lectures.add(new Pair(input[0], input[1]));
		}
		Collections.sort(lectures);

		for (Pair lecture : lectures) {
			if (!classrooms.isEmpty() && classrooms.peek() <= lecture.s) {
				classrooms.poll();
			}
			classrooms.offer(lecture.t);
		}

		sb.append(classrooms.size());
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static class Pair implements Comparable<Pair> {
		private int s;
		private int t;

		public Pair(int s, int t) {
			this.s = s;
			this.t = t;
		}

		public Pair(String s, String t) {
			this.s = Integer.parseInt(s);
			this.t = Integer.parseInt(t);
		}

		@Override
		public int compareTo(Pair o) {
			if (this.s > o.s) {
				return 1;
			} else if (this.s == o.s) {
				if (this.t > o.t) {
					return 1;
				} else if (this.t == o.t) {
					return 0;
				}
			}
			return -1;
		}
	}

}
