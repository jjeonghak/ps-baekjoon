import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static Node[] nodes;
    static int[] parent;
    static PriorityQueue<Edge> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        init(n);
        for (int i=1; i<=n; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            nodes[i] = new Node(x, y);
        }
        for (int i=1; i<=n; i++)
            for (int j=i+1; j<=n; j++)
                pq.add(new Edge(i, j, calDistance(i, j)));

        int cnt = 0;
        double ans = 0;
        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (find(a) != find(b)) {
                union(a, b);
                cnt++;
            }
        }

        while (!pq.isEmpty() && cnt != n - 1) {
            Edge e = pq.peek();
            pq.poll();
            int a = e.node[0];
            int b = e.node[1];

            if (find(a) != find(b)) {
                union(a, b);
                ans += e.cost;
                cnt++;
            }
        }
        System.out.println(String.format("%.2f", ans));
        br.close();
    }

    static int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    static void union(int a, int b) {
        int aParent = find(a);
        int bParent = find(b);

        if (aParent < bParent)
            parent[bParent] = aParent;
        else
            parent[aParent] = bParent;
        return;
    }

    private static double calDistance(int i, int j) {
        double xPow = Math.pow((long) nodes[i].x - nodes[j].x, 2);
        double yPow = Math.pow((long) nodes[i].y - nodes[j].y, 2);

        return Math.sqrt(xPow + yPow);
    }

    static void init(int n) {
        nodes = new Node[n + 1];
        parent = new int[n + 1];
        for (int i=1; i<=n; i++)
            parent[i] = i;
        return;
    }
}

class Node {
    int x;
    int y;

    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Edge implements Comparable {
    int[] node = new int[2];
    double cost;

    public Edge(int a, int b, double cost) {
        this.node[0] = a;
        this.node[1] = b;
        this.cost = cost;
    }


    @Override
    public int compareTo(Object o) {
        double result = this.cost - ((Edge) o).cost;
        if (result < 0)
            return -1;
        else if (result > 0)
            return 1;
        else
            return 0;
    }
}
