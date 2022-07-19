import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static Stack<Character> tag = new Stack<>();

    public static void pop_back() {
        while (!tag.isEmpty()) {
            System.out.print(tag.peek());
            tag.pop();
        }
        return;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] s = br.readLine().toCharArray();

        boolean tagCheck = false;
        for (int i=0; i<s.length; i++) {
            if (s[i] == '<') {
                tagCheck = true;
                pop_back();
            }
            if (tagCheck)
                System.out.print(s[i]);
            else {
                if (s[i] == ' ') {
                    pop_back();
                    System.out.print(' ');
                }
                else
                    tag.push(s[i]);
            }
            if (s[i] == '>')
                tagCheck = false;
        }
        pop_back();
    }
}
