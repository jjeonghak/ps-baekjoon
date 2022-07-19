import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        char[] s = st.nextToken().toCharArray();
        List<String> result = new ArrayList<>();
        for (int i=0; i<s.length; i++) {
            StringBuilder suffix = new StringBuilder(String.copyValueOf(s, i, s.length - i));
            result.add(suffix.toString());
        }
        result.sort(Comparator.naturalOrder());
        result.forEach(r -> System.out.println(r));
    }
}
