import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        char[] s = st.nextToken().toCharArray();
        char c = s[0];
        int result = 0;
        for (int i=1; i<s.length; i++) {
            if (c != s[i]) {
                c = s[i];
                result++;
            }
        }
        System.out.println((result + 1) / 2);
    }
}
