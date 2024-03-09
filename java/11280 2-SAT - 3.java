import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int id = 0;
    static int[] dfsDepth, sccNum;
    static boolean[] finished;
    static Stack<Integer> s = new Stack<>();
    static List<Integer>[] nodes;
    static List<List<Integer>> sccRepository = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        dfsDepth = new int[2 * n + 1];
        sccNum = new int[2 * n + 1];
        finished = new boolean[2 * n + 1];
        nodes = new List[2 * n + 1];
        for (int i=1; i<2*n+1; i++)
            nodes[i] = new ArrayList<>();

        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            a = normalIndex(a);
            b = normalIndex(b);
            nodes[notIndex(a)].add(b);
            nodes[notIndex(b)].add(a);
        }

        for (int i=1; i<2*n+1; i++)
            if (!finished[i])
                sccDfs(i);

        for (int i=1; i<2*n+1; i+=2) {
            if (sccNum[i] == sccNum[i + 1]) {
                System.out.println(0);
                return;
            }
        }
        System.out.println(1);

    }


    static int normalIndex(int index) {
        return index < 0 ? -index * 2 : 2 * index - 1;
    }

    static int notIndex(int index) {
        return index % 2 == 0 ? index - 1 : index + 1;
    }

    private static int sccDfs(int index) {
        dfsDepth[index] = ++id;
        s.push(index);

        int result = dfsDepth[index];
        for (int i=0; i<nodes[index].size(); i++) {
            Integer next = nodes[index].get(i);

            if (dfsDepth[next] == 0)
                result = Math.min(result, sccDfs(next));
            else if (!finished[next])
                result = Math.min(result, dfsDepth[next]);
        }

        if (dfsDepth[index] == result) {
            List<Integer> scc = new ArrayList<>();
            int currentSccNum = sccRepository.size() + 1;
            while (true) {
                Integer sccIndex = s.pop();
                finished[sccIndex] = true;
                scc.add(sccIndex);
                sccNum[sccIndex] = currentSccNum;
                if (sccIndex == index)
                    break;
            }
            sccRepository.add(scc);
        }
        return result;
    }
}
