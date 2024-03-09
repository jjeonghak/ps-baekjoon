import java.io.*;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int ans = 0, mul = 1;
        char[] s = br.readLine().toCharArray();
        Stack<Character> st = new Stack<>();
        for (int i=0; i<s.length; i++) {
            if (s[i] == '(') {
                mul *= 2;
                st.push('(');
            } else if (s[i] == '[') {
                mul *= 3;
                st.push('[');
            } else if (s[i] == ')') {
                if (st.isEmpty() || st.peek() != '(') {
                    ans = 0;
                    break;
                }
                if (s[i - 1] == '(')
                    ans += mul;
                st.pop();
                mul /= 2;
            } else {
                if (st.isEmpty() || st.peek() != '[') {
                    ans = 0;
                    break;
                }
                if (s[i - 1] == '[')
                    ans += mul;
                st.pop();
                mul /= 3;
            }
        }
        if (st.isEmpty())
            bw.write(ans + "\n");
        else
            bw.write(0 + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
