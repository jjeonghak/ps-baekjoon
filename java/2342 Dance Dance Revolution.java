import java.io.*;
import java.util.Arrays;

public class Main {

    private static int[] map;
    private static int[][][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        map = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt)
            .filter(i -> i != 0)
            .toArray();
        dp = new int[map.length][5][5];
        sb.append(solution(1, map[0], 0) + 2);
        bw.write(sb.toString());
        bw.close();
        br.close();
    }

    private static int solution(int index, int lb, int rb) {
        if (index == map.length) {
            return 0;
        }
        if (dp[index][lb][rb] != 0) {
            return dp[index][lb][rb];
        }
        int target = map[index];
        if (lb == target || rb == target) {
            dp[index][lb][rb] = solution(index + 1, lb, rb) + 1;
            return dp[index][rb][lb] = dp[index][lb][rb];
        }
        int temp1 = lb == 0 ? 2 : (lb + target) % 2 == 0 ? 4 : 3;
        int temp2 = rb == 0 ? 2 : (rb + target) % 2 == 0 ? 4 : 3;
        dp[index][lb][rb] = Math.min(
            solution(index + 1, target, rb) + temp1,
            solution(index + 1, lb, target) + temp2
        );
        return dp[index][rb][lb] = dp[index][lb][rb];
    }
}
