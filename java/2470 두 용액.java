import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int[] arr;
    static int n, lb, rb, result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[n];

        for (int i=0; i<n; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(arr);
        binarySearch();
        System.out.println(lb + " " + rb);
        br.close();
    }

    private static void binarySearch() {
        int l = 0, r = n - 1;
        result = 2000000001;
        while (l < r) {
            int sum = arr[l] + arr[r];
            int absSum = Math.abs(sum);
            int mid = (l + r) / 2;
            if (absSum < result) {
                lb = arr[l];
                rb = arr[r];
                result = absSum;
                if (sum == 0)
                    return;
            }
            if (sum < 0) {
                l++;
            } else {
                r--;
            }
        }
        return;
    }
}
