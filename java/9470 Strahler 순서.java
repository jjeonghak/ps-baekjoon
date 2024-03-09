import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int[] degree;
    static int[] strahler;
    static int[] check;
    static List<Integer>[] edges;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t != 0) {
            t--;
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            degree = new int[m + 1];
            check = new int[m + 1];
            strahler = new int[m + 1];
            edges = new List[m + 1];
            for (int i=1; i<=m; i++)
                edges[i] = new ArrayList<>();

            for (int i=0; i<p; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                edges[a].add(b);
                degree[b]++;
            }
            sb.append(k).append(" ").append(topologySort(m)).append("\n");
        }
        System.out.println(sb);
    }

    static int topologySort(int m) {
        Queue<Edge> q = new LinkedList<>();
        int endIndex = m;
        for (int i=1; i<=m; i++)
            if (degree[i] == 0)
                q.offer(new Edge(i, 1));
        while (!q.isEmpty()) {
            Edge current = q.poll();
            for (int i=0; i<edges[current.index].size(); i++) {
                Integer next = edges[current.index].get(i);
                if (strahler[next] < current.depth) {
                    check[next] = 0;
                    strahler[next] = current.depth;
                } else if (strahler[next] == current.depth) {
                    if (check[next] == 0) {
                        strahler[next]++;
                        check[next] = 1;
                    } else {
                        check[next] = 0;
                    }
                }
                if (--degree[next] == 0)
                    q.offer(new Edge(next, strahler[next]));
            }
            if (q.isEmpty())
                endIndex = current.index;
        }
        return strahler[endIndex];
    }
}

class Edge {
    int index;
    int depth;

    public Edge(int index, int depth) {
        this.index = index;
        this.depth = depth;
    }
}
