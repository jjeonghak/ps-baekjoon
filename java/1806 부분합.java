import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());

        int[] arr = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i=0; i<n; i++) 
            arr[i] =  Integer.parseInt(st.nextToken());
        
        int lp = 0, rp = 0, sum = arr[0], minCnt = n + 1;
        while (true) {
            if (sum >= s) {
                minCnt = Math.min(rp - lp + 1, minCnt);
                sum -= arr[lp++];
            } else {
                sum += arr[++rp];
            }
            if (rp == n)
                break;
        }
        if (minCnt != n + 1)
            System.out.println(minCnt);
        else
            System.out.println(0);
    }
}
