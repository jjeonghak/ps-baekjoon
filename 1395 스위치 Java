import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int r;
    static int[] indexTree;
    static int[] lazy;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (r=1; r<n; r <<= 1);
        indexTree = new int[r * 2 + 1];
        lazy = new int[r * 2 + 1];

        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int o = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            if (t < s) {
                int temp = t;
                t = s;
                s = temp;
            }

            if (o == 0)
                change(1, 1, n, s, t);
            else if (o == 1)
                bw.write(query(1, 1, n, s, t) + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }

    static void change(int index, int s, int e, int lb, int rb) {
        propagation(index, s, e);
        if (rb < s || e < lb)
            return;
        if (lb <= s && e <= rb) {
            indexTree[index] = e - s + 1 - indexTree[index];
            if (s != e) {
                lazy[index * 2] ^= 1;
                lazy[index * 2 + 1] ^= 1;
            }
            return;
        }
        int mid = (s + e) / 2;
        change(index * 2, s, mid, lb, rb);
        change(index * 2 + 1, mid + 1, e, lb, rb);
        indexTree[index] = indexTree[index * 2] + indexTree[index * 2 + 1];
        return;
    }

    static void propagation(int index, int s, int e) {
        if (lazy[index] == 1) {
            lazy[index] = 0;
            indexTree[index] = e - s + 1 - indexTree[index];

            if (s != e) {
                lazy[index * 2] ^= 1;
                lazy[index * 2 + 1] ^= 1;
            }
        }
        return;
    }

    static int query(int index, int s, int e, int lb, int rb) {
        propagation(index, s, e);
        if (rb < s || e < lb)
            return 0;
        if (lb <= s && e <= rb)
            return indexTree[index];
        int mid = (s + e) / 2;
        return query(index * 2, s, mid, lb, rb)
                + query(index * 2 + 1, mid + 1, e, lb, rb);
    }
}
