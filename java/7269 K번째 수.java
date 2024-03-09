import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int r;
    static List<Integer>[] indexTree;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (r=1; r<n; r <<= 1);
        int indexTreeSize = r << 1;
        indexTree = new List[indexTreeSize + 1];
        for (int i=0; i<=indexTreeSize; i++)
            indexTree[i] = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i=1; i<=n; i++) {
            int v = Integer.parseInt(st.nextToken());
            update(1, n, 1, i, v);
        }
        for (int i=1; i<=indexTreeSize; i++)
            Collections.sort(indexTree[i]);
        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            int lb = -1000000001, rb = 1000000001;
            while (lb <= rb) {
                int mid = (lb + rb) / 2;
                int result = query(1, n, 1, a, b, mid);
                if (result < c) {
                    lb = mid + 1;
                } else {
                    rb = mid - 1;
                }
            }
            sb.append(rb).append("\n");
        }
        System.out.println(sb.toString());
    }

    static void update(int s, int e, int index, int indexNum, int v) {
        if (indexNum < s || e < indexNum)
            return;
        indexTree[index].add(v);
        if (s != e) {
            int mid = (s + e) / 2;
            update(s, mid, index * 2, indexNum, v);
            update(mid + 1, e, index * 2 + 1, indexNum, v);
        }
        return;
    }

    static int query(int s, int e, int index, int lb, int rb, int v) {
        if (rb < s || e < lb)
            return 0;
        else if (lb <= s && e <= rb)
            return lowerBound(index, v);
        int mid = (s + e) / 2;
        return query(s, mid, index * 2, lb, rb, v)
                + query(mid + 1, e, index * 2 + 1, lb, rb, v);
    }

    static int lowerBound(int index, int v) {
        int lb = 0, rb = indexTree[index].size();

        while (lb < rb) {
            int mid = (lb + rb) / 2;
            if (indexTree[index].get(mid) >= v) {
                rb = mid;
            } else {
                lb = mid + 1;
            }
        }
        return rb;
    }
}
