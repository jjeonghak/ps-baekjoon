import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        int k = Integer.parseInt(br.readLine());

        System.out.println(binarySearch(n, k));
    }

    static long binarySearch(long n, int k) {
        long l = 1, r = k;
        while (l < r) {
            long mid = (l + r) / 2;
            int result = 0;
            for (int i=1; i<=n; i++) {
                result += Math.min(n, mid / i);
            }
            if (result < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r;
    }
}
