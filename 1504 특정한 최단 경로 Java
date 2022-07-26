import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static final int INF = 2147483647;
    static int n;
    static List<Edge>[] nodes;

    static int[] v = new int[2];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        nodes = new List[n + 1];
        for (int i=1; i<=n; i++)
            nodes[i] = new ArrayList<>();

        for (int i=0; i<e; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            nodes[a].add(new Edge(b, c));
            nodes[b].add(new Edge(a, c));
        }

        st = new StringTokenizer(br.readLine());
        v[0] = Integer.parseInt(st.nextToken());
        v[1] = Integer.parseInt(st.nextToken());

        long path1;
        path1 = dijkstra(1, v[0]);
        path1 += dijkstra(v[0], v[1]);
        path1 += dijkstra(v[1], n);

        long path2;
        path2 = dijkstra(1, v[1]);
        path2 += dijkstra(v[1], v[0]);
        path2 += dijkstra(v[0], n);


        if (path1 >= INF && path2 >= INF)
            System.out.println(-1);
        else {
            long ans = path1 < path2 ? path1 : path2;
            System.out.println(ans);
        }
        br.close();
    }

    static long dijkstra(int start, int end) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.offer(new Edge(start, 0));
        boolean[] check = new boolean[n + 1];
        long result = INF;
        while (!pq.isEmpty()) {
            Edge current = pq.poll();
            check[current.node] = true;
            if (current.node == end) {
                result = current.cost;
                break;
            }
            for (int i=0; i<nodes[current.node].size(); i++) {
                Edge next = nodes[current.node].get(i);

                if (!check[next.node])
                    pq.offer(new Edge(next.node, current.cost + next.cost));
            }
        }
        return result;
    }
}

class Edge implements Comparable {
    int node;
    long cost;

    public Edge(int node, long cost) {
        this.node = node;
        this.cost = cost;
    }


    @Override
    public int compareTo(Object o) {
        long result = this.cost - ((Edge) o).cost;
        if (result < 0)
            return -1;
        else if (result > 0)
            return 1;
        else
            return 0;
    }
}
