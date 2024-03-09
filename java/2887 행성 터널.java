import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static int[] parent;
    static PriorityQueue<Edge> pq= new PriorityQueue<>();
    static Node[] xpq, ypq, zpq;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        init(n);
        for (int i=1; i<=n; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());

            xpq[i - 1] = new Node(i, x);
            ypq[i - 1] = new Node(i, y);
            zpq[i - 1] = new Node(i, z);
        }

        Arrays.sort(xpq);
        Arrays.sort(ypq);
        Arrays.sort(zpq);

        for (int i=0; i<n - 1; i++) {
            int xAbs = Math.abs(xpq[i].value - xpq[i + 1].value);
            int yAbs = Math.abs(ypq[i].value - ypq[i + 1].value);
            int zAbs = Math.abs(zpq[i].value - zpq[i + 1].value);
            pq.add(new Edge(xpq[i].index, xpq[i + 1].index, xAbs));
            pq.add(new Edge(ypq[i].index, ypq[i + 1].index, yAbs));
            pq.add(new Edge(zpq[i].index, zpq[i + 1].index, zAbs));
        }

        int cnt = 0;
        long ans = 0;
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
        System.out.println(ans);
        br.close();
    }

    private static void union(int a, int b) {
        int aParent = find(a);
        int bParent = find(b);
        if (aParent < bParent)
            parent[bParent] = aParent;
        else
            parent[aParent] = bParent;
        return;
    }

    private static int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    private static void init(int n) {
        parent = new int[n + 1];
        xpq = new Node[n];
        ypq = new Node[n];
        zpq = new Node[n];
        for (int i=1; i<=n; i++)
            parent[i] = i;
        return;
    }
}

class Node implements Comparable {
    int index;
    int value;

    public Node(int index, int value) {
        this.index = index;
        this.value = value;
    }

    @Override
    public int compareTo(Object o) {
        return this.value - ((Node) o).value;
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
