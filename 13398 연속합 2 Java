import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] arr;
    static int[] rdp;
    static int[] ldp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i=0; i<n; i++)
            arr[i] = Integer.parseInt(st.nextToken());
        rdp = new int[n];
        ldp = new int[n];
        int sum = 0;
        ldp[0] = arr[0];
        int ans = ldp[0];
        for (int i=1; i<n; i++) {
            ldp[i] = Math.max(ldp[i - 1] + arr[i], arr[i]);
            ans = Math.max(ans, ldp[i]);
        }
        rdp[n - 1] = arr[n - 1];
        for (int i=n-2; i>=0; i--) {
            rdp[i] = Math.max(rdp[i + 1] + arr[i], arr[i]);
            ans = Math.max(ans, rdp[i]);
        }
        for (int i=1; i<n-1; i++)
            ans = Math.max(ans, ldp[i - 1] + rdp[i + 1]);
        System.out.println(ans);
    }
}
