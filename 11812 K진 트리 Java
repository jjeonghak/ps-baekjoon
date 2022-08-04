import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int k;
    static long n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Long.parseLong(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        for (int i=0; i<q; i++) {
            st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            if (k != 1)
                sb.append(query(a, b)).append("\n");
            else
                sb.append(Math.abs(a - b)).append("\n");
        }
        System.out.println(sb);
        br.close();
    }

    static long getDepth(long node) {
        int depth = 0;
        while ((Math.pow(k, depth) - 1)/(k - 1) + 1 <= node)
            depth++;
        return depth;
    }

    static long getParent(long node) {
        return (node - 2)/k + 1;
    }

    static long query(long a, long b) {
        long result = 0;
        long aDepth = getDepth(a);
        long bDepth = getDepth(b);
        if (aDepth < bDepth) {
            while (aDepth != bDepth) {
                bDepth--;
                b = getParent(b);
                result++;
            }
        } else if (bDepth < aDepth) {
            while (aDepth != bDepth) {
                aDepth--;
                a = getParent(a);
                result++;
            }
        }
        while (a != b) {
            a = getParent(a);
            b = getParent(b);
            result += 2;
        }
        return result;
    }
}
