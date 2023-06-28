import java.io.*;

class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		boolean[][] map = new boolean[101][101];

		int n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			String[] input = br.readLine().split(" ");
			int x = Integer.parseInt(input[0]);
			int y = Integer.parseInt(input[1]);
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 10; k++)
					map[x + j][y + k] = true;
		}
		int answer = 0;
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
				if (map[i][j])
					answer += 1;
		bw.write(String.valueOf(answer));
		bw.close();
		br.close();
	}
}
