import java.io.*;
import java.util.*;

public class Main {

    static List<Node>[] nodes;
    static int[] xDegree, yDegree, indexCnt;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());


        xDegree = new int[n + 1];
        yDegree = new int[n + 1];
        indexCnt = new int[n + 1];
        nodes = new List[n + 1];
        for (int i=1; i<=n; i++)
            nodes[i] = new ArrayList<>();

        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            nodes[x].add(new Node(y, k));
            xDegree[x] = 1;
            yDegree[y]++;
        }

        topologySort(n);
        for (int i=1; i<=n; i++)
            if (xDegree[i] != 1)
                sb.append(i).append(" ").append(indexCnt[i]).append("\n");
        System.out.println(sb);
    }

    static void topologySort(int n) {
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(n, 1));
        indexCnt[n] = 1;
        while (!q.isEmpty()) {
            Node current = q.poll();

            for (int i=0; i<nodes[current.index].size(); i++) {
                Node next = nodes[current.index].get(i);
                indexCnt[next.index] += indexCnt[current.index] * next.cnt;
                yDegree[next.index]--;
                if (yDegree[next.index] == 0)
                    q.offer(next);
            }

        }
        return;
    }
}

class Node {
    int index;
    int cnt;

    public Node(int index, int cnt) {
        this.index = index;
        this.cnt = cnt;
    }
}
