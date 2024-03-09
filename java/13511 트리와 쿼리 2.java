import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int n;
    static int[] depth;
    static long[] cost;
    static int[][] dp;
    static List<Pair>[] path;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(st.nextToken());
        depth = new int[n + 1];
        path = new List[n + 1];
        cost = new long[n + 1];
        dp = new int[n + 1][18];
        for (int i=0; i<=n; i++)
            path[i] = new ArrayList<>();
        for (int i=0; i<n-1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            
            path[v].add(new Pair(u, (long) w));
            path[u].add(new Pair(v, (long) w));
        }

        initMain();

        int m = Integer.parseInt(br.readLine());
        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int f = Integer.parseInt(st.nextToken());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            if (f == 1)
                sb.append(queryCost(u, v)).append("\n");
            else {
                int k = Integer.parseInt(st.nextToken());
                sb.append(queryPath(u, v, k)).append("\n");
            }
        }
        System.out.println(sb);
    }

    static void initMain() {
        Queue<Pair> q = new LinkedList<>();
        boolean[] check = new boolean[n + 1];
        check[1] = true;
        q.offer(new Pair(1, 0, 0));
        while (!q.isEmpty()) {
            Pair current = q.poll();
            depth[current.index] = current.d;
            cost[current.index] = current.cost;
            for (int i=0; i<path[current.index].size(); i++) {
                Pair next = path[current.index].get(i);
                if (!check[next.index]) {
                    check[next.index] = true;
                    dp[next.index][0] = current.index;
                    q.offer(new Pair(next.index, current.cost + next.cost, current.d + 1));
                }
            }
        }

        for (int i=1; i<18; i++)
            for (int j=1; j<=n; j++)
                dp[j][i] = dp[dp[j][i - 1]][i - 1];
        return;
    }

    static int lca(int a, int b) {
        if (depth[a] > depth[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        for (int i=17; i>=0; i--) {
            if (depth[b] >= depth[a] + (1 << i)) {
                b = dp[b][i];
            }
        }
        if (a == b)
            return a;
        for (int i=17; i>=0; i--) {
            if (dp[a][i] != dp[b][i]) {
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        return dp[a][0];
    }

    static long queryCost(int a, int b) {
        int parent = lca(a, b);
        return cost[a] + cost[b] - 2 * cost[parent];
    }

    static int queryPath(int a, int b, int k) {
        int parent = lca(a, b);
        int result;
        int diff = depth[a] - depth[parent] + 1;
        if (k > diff) {
            k -= diff;
            diff = depth[b] - depth[parent];
            k = diff - k;
            result = b;
            for (int i=17; i>=0; i--) {
                if (k >= (1 << i)) {
                    k -= (1 << i);
                    result = dp[b][i];
                    b = dp[b][i];
                }
            }
        } else {
            result = a;
            for (int i=17; i>=0; i--) {
                if (k > (1 << i)) {
                    k -= (1 << i);
                    result = dp[a][i];
                    a = dp[a][i];
                }
            }
        }
        return result;
    }
}

class Pair {
    int index;
    long cost;
    int d;

    public Pair(int index, long cost) {
        this.index = index;
        this.cost = cost;
    }

    public Pair(int index, long cost, int d) {
        this.index = index;
        this.cost = cost;
        this.d = d;
    }
}
