import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static List<Edge>[] nodes;
    static int[][] map;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int n;
        int t = 0;
        while ((n = Integer.parseInt(br.readLine())) != 0) {
            t++;
            sb.append("Problem ").append(t).append(": ");
            map = new int[n][n];
            for (int i=0; i<n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j=0; j<n; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            makeEdge(n);
            sb.append(dijkstra(n)).append("\n");
        }
        System.out.println(sb);
    }

    private static int dijkstra(int n) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.offer(new Edge(0, map[0][0]));
        boolean[] check = new boolean[n * n];
        int result = -1;
        while (!pq.isEmpty()) {
            Edge current = pq.poll();
            check[current.node] = true;
            if (current.node == n * n - 1) {
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

    private static void makeEdge(int n) {
        nodes = new List[n * n];
        for (int i=0; i<n*n; i++)
            nodes[i] = new ArrayList<>();
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int index = i * n + j;
                for (int k=0; k<4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx>=0 && nx<n && ny>=0 && ny<n) {
                        switch (k) {
                            case 0:
                                nodes[index].add(new Edge(index + 1, map[nx][ny]));
                                break;
                            case 1:
                                nodes[index].add(new Edge(index + n, map[nx][ny]));
                                break;
                            case 2:
                                nodes[index].add(new Edge(index - 1, map[nx][ny]));
                                break;
                            default:
                                nodes[index].add(new Edge(index - n, map[nx][ny]));
                                break;
                        }
                    }

                }
            }
        }
        return;
    }
}

class Edge implements Comparable{
    int node;
    int cost;

    public Edge(int node, int cost) {
        this.node = node;
        this.cost = cost;
    }


    @Override
    public int compareTo(Object o) {
        return this.cost - ((Edge) o).cost;
    }
}
