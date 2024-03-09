import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int r;
    static long[] indexTree;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for (r=1; r<n; r <<= 1);
        indexTree = new long[r << 1];
        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if (a == 1)
                modify(r + b - 1, c - indexTree[r + b - 1]);
            else {
                if (b > c) {
                    int temp = b;
                    b = c;
                    c = temp;
                }
                sb.append(query(1, r, 1, b, c)).append("\n");
            }
        }
        System.out.println(sb);
    }

    static void modify(int node, long k) {
        if (node == 0)
            return;
        indexTree[node] += k;
        modify(node / 2, k);
        return;
    }

    static long query(int s, int e, int node, int lb, int rb) {
        if (rb < s || e < lb) {
            return 0;
        } else if (lb <= s && e <= rb) {
          return indexTree[node];
        }
        int mid = (s + e) / 2;
        return query(s, mid, node * 2, lb, rb)
                + query(mid + 1, e, node * 2 + 1, lb, rb);
    }
}
