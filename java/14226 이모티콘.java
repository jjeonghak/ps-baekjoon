import java.io.*;
import java.util.*;

class Main {

	private static boolean[][] visit;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int s = Integer.parseInt(br.readLine());
		visit = new boolean[1001][1001];
		sb.append(solution(s));

		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static int solution(int s) {
		int result = 0;
		Queue<Status> queue = new LinkedList<>();
		queue.offer(new Status(0, 1, 0));
		while (!queue.isEmpty()) {
			Status status = queue.poll();

			if (status.current == s) {
				result = status.time;
				break;
			}

			if (!visit[status.current][status.current] && status.current != status.board && status.current < s) {
				queue.offer(Status.copy(status));
				visit[status.current][status.current] = true;
			}

			if (status.board + status.current <= s && !visit[status.board][status.board + status.current]) {
				queue.offer(Status.paste(status));
				visit[status.board][status.board + status.current] = true;
			}

			if (status.current != 0 && !visit[status.board][status.current - 1]) {
				queue.offer(Status.minus(status));
				visit[status.board][status.current - 1] = true;
			}
		}
		return result;
	}

	public static class Status {
		public int time;
		public int board;
		public int current;

		public static Status copy(Status s) {
			return new Status(s.time + 1, s.current, s.current);
		}

		public static Status paste(Status s) {
			return new Status(s.time + 1, s.board, s.current + s.board);
		}

		public static Status minus(Status s) {
			return new Status(s.time + 1, s.board, s.current - 1);
		}

		public Status(int time, int board, int current) {
			this.time = time;
			this.board = board;
			this.current = current;
		}
	}

}
