import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static final int INF = 2147483647;
    static int finalTime;
    static List<Edge>[] nodes;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());
        while (t != 0) {
            t--;
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            nodes = new List[n + 1];
            dp = new int[n + 1][m + 1];
            for (int i=1; i<=n; i++) {
                nodes[i] = new ArrayList<>();
                Arrays.fill(dp[i], INF);
            }

            for (int i=0; i<k; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());

                nodes[u].add(new Edge(v, c, d));
            }

            dijkstra(n, m);
            if (finalTime == INF)
                sb.append("Poor KCM\n");
            else
                sb.append(finalTime).append("\n");

        }
        System.out.println(sb);
        br.close();
    }

    static void dijkstra(int n, int m) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        finalTime = INF;
        for (int i=1; i<=n; i++)
            Collections.sort(nodes[i], new Comparator<Edge>() {
                @Override
                public int compare(Edge o1, Edge o2) {
                    int result = o1.cost - o2.cost;
                    if (result < 0)
                        return -1;
                    else if (result == 0) {
                        if (o1.time - o2.time < 0)
                            return -1;
                        return 0;
                    }
                    return 1;
                }
            });
        pq.offer(new Edge(1, 0, 0));
        while (!pq.isEmpty()) {
            Edge current = pq.poll();

            if (current.node == n) {
                finalTime = current.time;
                break;
            }
            for (int i=0; i<nodes[current.node].size(); i++) {
                Edge next = nodes[current.node].get(i);
                int totalCost = current.cost + next.cost;
                int totalTime = current.time + next.time;

                if (totalCost > m)
                    break;
                else if (totalTime < dp[next.node][totalCost]) {
                    for (int j=totalCost; j<=m; j++)
                        if (dp[next.node][j] > totalTime)
                            dp[next.node][j] = totalTime;
                    pq.offer(new Edge(next.node, totalCost, totalTime));
                }
            }
        }
        return;
    }
}

class Edge implements Comparable {
    int node;
    int cost;
    int time;

    public Edge(int node, int cost, int time) {
        this.node = node;
        this.cost = cost;
        this.time = time;
    }

    @Override
    public int compareTo(Object o) {
        int result = this.time - ((Edge) o).time;
        if (result < 0)
            return -1;
        else if (result == 0) {
            if (this.cost - ((Edge) o).cost < 0)
                return -1;
            return 0;
        }
        return 1;
    }
}
