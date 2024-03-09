import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static int[] parent;
    static Node[] nodes;
    static PriorityQueue<Edge> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        init(n);

        for (int i=1; i<=n; i++) {
            st = new StringTokenizer(br.readLine());
            double x = Double.parseDouble(st.nextToken());
            double y = Double.parseDouble(st.nextToken());
            nodes[i] = new Node(x, y);
        }

        for (int i=1; i<=n; i++)
            for (int j=i+1; j<=n; j++)
                pq.add(new Edge(i, j, calDistance(nodes[i], nodes[j])));

        int cnt = 0;
        double ans = 0;
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

    private static double calDistance(Node a, Node b) {
        double xLength = a.x - b.x;
        double yLength = a.y - b.y;

        double powSum = Math.pow(xLength, 2) + Math.pow(yLength, 2);
        return (double) Math.round(Math.sqrt(powSum) * 100) / 100;
    }

    static void init(int n) {
        nodes = new Node[n + 1];
        parent = new int[n + 1];
        for (int i=1; i<=n; i++)
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

        if (aParent < bParent)
            parent[bParent] = aParent;
        else if (aParent > bParent)
            parent[aParent] = bParent;
        return;
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
        return 0;
    }
}

class Node {
    double x;
    double y;

    public Node(double x, double y) {
        this.x = x;
        this.y = y;
    }
}
