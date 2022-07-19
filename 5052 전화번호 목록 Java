import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());
        while (t != 0) {
            t--;
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());

            String[] numList = new String[n];
            for (int i=0; i<n; i++) {
                st = new StringTokenizer(br.readLine());
                String index = st.nextToken();
                numList[i] = index;
            }
            Arrays.sort(numList);
            int result = 1;
            for (int i=0; i<numList.length - 1; i++) {
                if (numList[i].length() < numList[i + 1].length()) {
                    result = numList[i + 1].substring(0, numList[i].length()).compareTo(numList[i]);
                } else {
                    result = numList[i].substring(0, numList[i + 1].length()).compareTo(numList[i + 1]);
                }
                if (result == 0)
                    break;
            }
            if (result == 0)
                System.out.println("NO");
            else
                System.out.println("YES");
        }
    }
}
