import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static double result;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine()) != null) {
//        while (!(line = br.readLine()).equals("")) {
            TrieNode root = new TrieNode(false);
            int n = Integer.parseInt(line);

            result = 0;

            for (int i=0; i<n; i++) {
                char[] wordInput = br.readLine().toCharArray();
                TrieNode current = root;
                for (int j=0; j<wordInput.length; j++) {
                    if (j == wordInput.length - 1)
                        current = current.insert(wordInput[j], true);
                    else
                        current = current.insert(wordInput[j], false);
                }
            }
            if (root.childCnt == 1)
                dfs(root, 1);
            else
                dfs(root, 0);
            sb.append(String.format("%.2f", result / n)).append("\n");
//            System.out.println("-----------------------");
        }
        System.out.println(sb);
    }

    static void dfs(TrieNode node, int pathCnt) {
        if (node.isFinish) {
            result += pathCnt;
//            System.out.println("isFinish: " + result);
        }
        if (node.childCnt != 1 || node.isFinish) {
//            System.out.println("childCnt: " + node.childCnt + " pathCnt: " + pathCnt);
            pathCnt++;
        }
        if (node.childCnt != 0) {
            TrieNode[] child = node.child;
            for (int i = 0; i < 26; i++) {
                if (child[i] != null) {
//                    System.out.println("index: " + (char)(i + 'a'));
                    dfs(child[i], pathCnt);
                }
            }
        }
    }
}

class TrieNode {
    boolean isFinish;
    int childCnt;
    TrieNode[] child = new TrieNode[26];

    public TrieNode(boolean isFinish) {
        this.isFinish = isFinish;
        this.childCnt = 0;
    }

    public TrieNode insert(char c, boolean isFinish) {
        int index = c - 'a';
        if (child[index] == null) {
            child[index] = new TrieNode(isFinish);
            childCnt++;
        } else if (isFinish == true)
            child[index].isFinish = true;
        return child[index];
    }
}
