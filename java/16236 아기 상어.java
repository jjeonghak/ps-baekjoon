import java.io.*;
import java.util.*;

public class Main {

    private static final int[] dx = { 0, -1, 0, 1 };
    private static final int[] dy = { -1, 0, 1, 0 };

    private static int[][] map;
    private static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();


        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        int[] start = {0, 0};

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(input[j]);
                if (map[i][j] == 9) {
                    start[0] = i;
                    start[1] = j;
                    map[i][j] = 0;
                }
            }
        }

        int size = 2;
        int cnt = 0;
        int time = 0;

        while (true) {
            PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[0] != o2[0] 
                ? Integer.compare(o1[0], o2[0]) : (o1[1] != o2[1] 
                ? Integer.compare(o1[1], o2[1]) : Integer.compare(o1[2], o2[2])));
            boolean[][] check = new boolean[n][n];
            pq.offer(new int[] { 0, start[0], start[1]});
            boolean finish = false;

            while (!pq.isEmpty()) {
                int[] cur = pq.poll();

                if (map[cur[1]][cur[2]] != 0 && map[cur[1]][cur[2]] < size) {
                    if (++cnt == size) {
                        size++;
                        cnt = 0;
                    }
                    map[cur[1]][cur[2]] = 0;
                    time += cur[0];
                    start[0] = cur[1];
                    start[1] = cur[2];
                    finish = true;
                    break;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = cur[1] + dx[i];
                    int ny = cur[2] + dy[i];

                    if (0 <= nx && nx < n && 0 <= ny && ny < n && !check[nx][ny] && map[nx][ny] <= size) {
                        check[nx][ny] = true;
                        pq.offer(new int[] { cur[0] + 1, nx, ny });
                    }
                }
            }
            if (!finish) {
                break;
            }
        }

        sb.append(time);
        bw.write(sb.toString());
        bw.close();
        br.close();
    }
}
