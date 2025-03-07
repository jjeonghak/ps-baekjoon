import java.io.*;

public class Main {

    private static final int[][] dp = new int[10001][8];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            sb.append(solution(n, 7)).append("\n");
        }

        bw.write(sb.toString());
        bw.close();
        br.close();
    }

    private static int solution(int index, int flag) {
        if (dp[index][flag] != 0) {
            return dp[index][flag];
        }
        if (index < 2) {
            return dp[index][flag] = 1;
        }
        if (flag >= 7 && index >= 3) {
            dp[index][flag] += solution(index - 3, 7);
        }
        if (flag >= 3) {
            dp[index][flag] += solution(index - 2, 3);
        }
        dp[index][flag] += solution(index - 1, 1);
        return dp[index][flag];
    }
}
