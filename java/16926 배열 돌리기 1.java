import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int r = Integer.parseInt(input[2]);
        int[][] map = new int[n][m];

        for (int i = 0; i < n; i++) {
            map[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }
        int cnt = Math.min(n, m) / 2;
        while (r-- > 0) {
            for (int i = 0; i < cnt; i++) {
                int temp = map[i][i];
                for (int j = i; j < m - i - 1; j++) {
                    map[i][j] = map[i][j + 1];
                }
                for (int j = i; j < n - i - 1; j++) {
                    map[j][m - i - 1] = map[j + 1][m - i - 1];
                }
                for (int j = m - i - 1; j > i; j--) {
                    map[n - i - 1][j] = map[n - i - 1][j - 1];
                }
                for (int j = n - i - 1; j > i; j--) {
                    map[j][i] = map[j - 1][i];
                }
                map[i + 1][i] =  temp;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sb.append(map[i][j]).append(" ");
            }
            sb.append("\n");
        }
        bw.write(sb.toString());
        bw.close();
        br.close();
    }
}
