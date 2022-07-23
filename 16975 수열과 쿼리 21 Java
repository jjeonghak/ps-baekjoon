import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int r;
    static long[] indexTree;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        for (r = 1; r < n; r <<= 1);
        indexTree = new long[r << 1 + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i=0; i<n; i++)
            indexTree[r + i] = Long.parseLong(st.nextToken());
        int m = Integer.parseInt(br.readLine());
        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            if (Integer.parseInt(st.nextToken()) == 1) {
                int lb = Integer.parseInt(st.nextToken());
                int rb = Integer.parseInt(st.nextToken());
                long k = Long.parseLong(st.nextToken());

                update(1, r, 1, lb, rb, k);
            } else {
                int x = Integer.parseInt(st.nextToken());
                bw.write(query( r + x - 1) + "\n");
            }
        }
        bw.flush();
        bw.close();
        br.close();
    }

    static void update(int s, int e, int index, int lb, int rb, long k) {
        propagation(index, s, e);
        if (rb < s || e < lb)
            return;
        else if (lb <= s && e <= rb) {
            indexTree[index] += k;
//            System.out.println("s:" + s + " e:" + e + " lb:" + lb + " rb:" + rb);
//            System.out.println("update index: " + index + " indexTree: " + indexTree[index]);
            return;
        }
        int mid = (s + e) / 2;
        update(s, mid, index * 2, lb, rb, k);
        update(mid + 1, e, index * 2 + 1, lb, rb, k);
        return;
    }

    static void propagation(int index, int s, int e) {
        long lazy = indexTree[index];
        if (s != e && lazy != 0) {
            indexTree[index] = 0;
            indexTree[index * 2] += lazy;
            indexTree[index * 2 + 1] += lazy;
        }
        return;
    }

    static long query(int index) {
        long result = 0;
        while (index != 0) {
//            System.out.println("index: " + index + " indexTree: " + indexTree[index]);
            result += indexTree[index];
            index /= 2;
        }
        return result;
    }
}
