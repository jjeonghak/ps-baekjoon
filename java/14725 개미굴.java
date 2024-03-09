import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        TrieNode root = new TrieNode("");

        for (int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            TrieNode current = root;

            for (int j=0; j<k; j++) {
                String s = st.nextToken();
                TrieNode next = current.insert(s);
                if (next != null)
                    current = next;
            }
        }
        dfs(root, "");
        System.out.println(sb);
    }

    static void dfs(TrieNode node, String depth) {
        PriorityQueue<TrieNode> pq = node.childList;
        while (!pq.isEmpty()) {
            TrieNode child = pq.peek();
            pq.poll();
            sb.append(depth).append(child.index).append("\n");
            dfs(child, depth + "--");
        }
    }
}

class TrieNode implements Comparable{
    String index;
    List<String> childNames = new ArrayList<>();
    PriorityQueue<TrieNode> childList = new PriorityQueue<>();

    public TrieNode(String index) {
        this.index = index;
    }

    TrieNode getChild(String s) {
        Iterator<TrieNode> iter = childList.iterator();
        while (iter.hasNext()) {
            TrieNode node = iter.next();
            if (node.index.compareTo(s) == 0)
                return node;
        }
        return null;
    }

    public TrieNode insert(String s) {
        if (childNames.contains(s)) {
            return getChild(s);
        }
        else {
            TrieNode child = new TrieNode(s);
            this.childList.add(child);
            this.childNames.add(s);
            return child;
        }
    }

    @Override
    public int compareTo(Object o) {
        TrieNode temp = (TrieNode) o;
        return this.index.compareTo(temp.index);
    }
}
