import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int r;
    static int[] indexTree;
    static int[] lazy;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        for (r = 1; r < n; r <<= 1);
        indexTree = new int[r << 1 + 1];
        lazy = new int[r << 1 + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i=0; i<n; i++)
            indexTree[r + i] = Integer.parseInt(st.nextToken());
        initTree(1);
        int m = Integer.parseInt(br.readLine());
        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            if (Integer.parseInt(st.nextToken()) == 1) {
                int lb = Integer.parseInt(st.nextToken());
                int rb = Integer.parseInt(st.nextToken());
                int k = Integer.parseInt(st.nextToken());

                if (lb > rb) {
                    int temp = lb;
                    lb = rb;
                    rb = temp;
                }
                update(1, r, 1, lb + 1, rb + 1, k);
            } else {
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                if (x > y) {
                    int temp = x;
                    x = y;
                    y = temp;
                }
                bw.write(query( 1, r, 1, x + 1, y + 1) + "\n");
            }
        }
        bw.flush();
        bw.close();
        br.close();
    }

    static int initTree(int index) {
        if (r <= index)
            return indexTree[index];
        return indexTree[index] = initTree(index * 2) ^ initTree(index * 2 + 1);
    }
    static void update(int s, int e, int index, int lb, int rb, int k) {
        propagation(index, s, e);
        if (rb < s || e < lb)
            return;
        else if (lb <= s && e <= rb) {
            lazy[index] ^= k;
            propagation(index, s, e);
            return;
        }
        int mid = (s + e) / 2;
        update(s, mid, index * 2, lb, rb, k);
        update(mid + 1, e, index * 2 + 1, lb, rb, k);
        indexTree[index] = indexTree[index * 2] ^ indexTree[index * 2 + 1];
        return;
    }

    static void propagation(int index, int s, int e) {
        int k = lazy[index];
        lazy[index] = 0;
        if (s != e && k != 0) {
            lazy[index * 2] ^= k;
            lazy[index * 2 + 1] ^= k;
        }
        if ((e - s + 1) % 2 == 1)
            indexTree[index] ^= k * (e - s + 1);
        return;
    }

    static int query(int s, int e, int index, int lb, int rb) {
        propagation(index, s, e);
        if (rb < s || e < lb)
            return 0;
        if (lb <= s && e <= rb) {
            return indexTree[index];
        }
        int mid = (s + e) / 2;
        return query(s, mid, index * 2, lb, rb)
                ^ query(mid + 1, e, index * 2 + 1, lb, rb);
    }
}
