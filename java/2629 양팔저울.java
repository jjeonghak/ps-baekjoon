import java.io.*;
import java.util.*;

public class Main {

    private static int n;
    private static int[] input;
    private static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        n = Integer.parseInt(br.readLine());
        input = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt)
            .toArray();
        dp = new int[n + 1][40001];
        bt(0, 15000);
        int q = Integer.parseInt(br.readLine());
        int[] temp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt)
            .toArray();
        for (int i = 0; i < q; i++) {
            sb.append(temp[i] > 15000 || dp[n][temp[i] + 15000] <= 0 ? "N" : "Y").append(" ");
        }
        bw.write(sb.toString());
        bw.close();
        br.close();
    }

    private static int bt(int index, int total) {
        if (dp[index][total] != 0) {
            return dp[index][total];
        }
        if (index == n) {
            return dp[index][total] = total >= 15000 ? 1 : -1;
        }
        int temp1 = bt(index + 1, total + input[index]);
        int temp2 = bt(index + 1, total);
        int temp3 = bt(index + 1, total - input[index]);
        return dp[index][total] = temp1 | temp2 | temp3;
    }
}
