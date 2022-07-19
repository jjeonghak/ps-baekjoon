import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static int lp, rp;
    public static int check(char[] s, int lb, int rb) {
        int result = 0;
        while (lb < rb) {
            if (s[lb] == s[rb]) {
                lb++;
                rb--;
            }
            else {
                result = 1;
                break;
            }
        }
        lp = lb;
        rp = rb;
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t != 0) {
            t--;
            char[] s = br.readLine().toCharArray();
            int lb = 0, rb = s.length - 1;
            int result = check(s, lb, rb);
            if (result == 0)
                System.out.println(0);
            else {
                lb = lp;
                rb = rp;
                result = check(s, lb + 1, rb);
                if (result == 0)
                    System.out.println(1);
                else {
                    result = check(s, lb, rb - 1);
                    if (result == 0)
                        System.out.println(1);
                    else
                        System.out.println(2);
                }
            }
        }
    }
}
