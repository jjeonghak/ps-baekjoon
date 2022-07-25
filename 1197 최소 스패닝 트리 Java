import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static int[] parent;
    static PriorityQueue<Edge> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        parent = new int[v + 1];
        init(v);

        for (int i=0; i<e; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            pq.add(new Edge(a, b, c));
        }

        int cnt = 0, ans = 0;
        while (!pq.isEmpty() && cnt != v - 1) {
            Edge current = pq.peek();
            pq.poll();

            int a = current.node[0];
            int b = current.node[1];

            if (find(a) != find(b)) {
                union(a, b);
                ans += current.cost;
                cnt++;
            }
        }
        System.out.println(ans);
        br.close();
    }

    static void init(int v) {
        for (int i=1; i<=v; i++)
            parent[i] = i;
        return;
    }

    static int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    static void union(int a, int b) {
        int aParent = find(a);
        int bParent = find(b);

        if (aParent < bParent) {
            parent[bParent] = aParent;
        } else if (aParent > bParent) {
            parent[aParent] = bParent;
        }
        return;
    }
}

class Edge implements Comparable {
    int[] node = new int[2];
    int cost;

    public Edge(int a, int b, int cost) {
        this.node[0] = a;
        this.node[1] = b;
        this.cost = cost;
    }

    @Override
    public int compareTo(Object o) {
        return this.cost - ((Edge) o).cost;
    }
}
