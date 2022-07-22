import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static int total;
    static int cnt;
    static int longDepth;
    static String longWord;

    static int[] dx = {-1, 1, 0, 0, -1, 1, -1, 1};
    static int[] dy = {0, 0, -1, 1, -1, -1, 1, 1};
    static int[] score = {0, 0, 0, 1, 1, 2, 3, 5, 11};
    static char[][] map = new char[4][4];
    static boolean[][] check = new boolean[4][4];
    static StringBuilder pathWord = new StringBuilder();
    static List<TrieNode> leafList = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int w = Integer.parseInt(br.readLine());
        TrieNode rootNode = new TrieNode(true, false);
        StringBuilder resultSb = new StringBuilder();
        for (int i=0; i<w; i++) {
            char[] dic = br.readLine().toCharArray();
            TrieNode nextNode = rootNode;
            for (int j=0; j<dic.length; j++) {
                if (j == dic.length - 1)
                    nextNode = nextNode.insert(dic[j], true);
                else
                    nextNode = nextNode.insert(dic[j], false);
            }
        }
        br.readLine();
        int b = Integer.parseInt(br.readLine());
        for (int i=0; i<b; i++) {
            init();
            for (int j=0; j<4; j++) {
                char[] c = br.readLine().toCharArray();
                for (int k=0; k<4; k++)
                    map[j][k] = c[k];
            }
            for (int j=0; j<4; j++)
                for (int k=0; k<4; k++)
                    if (rootNode.hasChild(map[j][k])) {
//                        System.out.println("----------start(" + j + ", " + k + ")-----------");
                        search(j, k, rootNode.getChild(map[j][k]), 1);
                    }
            if (i != b - 1)
                br.readLine();

            resultSb.append(total).append(" ");
            if (longWord != null)
                resultSb.append(longWord).append(" ");
            resultSb.append(cnt).append("\n");
        }
        System.out.println(resultSb);
        br.close();
    }

    static void init() {
        total = 0;
        cnt = 0;
        longDepth = 0;
        longWord = null;
        pathWord = new StringBuilder();
        leafList.forEach(n -> n.isCheck = false);
        leafList.clear();
    }

    static void search(int x, int y, TrieNode node, int depth) {
//        System.out.println("index: " + map[x][y] + " leaf:" + node.isLeaf + " depth:" + depth);
        pathWord.append(map[x][y]);
        check[x][y] = true;
        if (node.isLeaf && !node.isCheck) {
            node.isCheck = true;
            leafList.add(node);
            if (depth >= longDepth) {
                makeString();
                longDepth = depth;
            }
            total += score[depth];
            cnt++;
//            System.out.println("cnt:" + cnt + " total:" + total + " long:" + longWord);
        }
        if (node.childCnt != 0) {
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !check[nx][ny] && node.hasChild(map[nx][ny]))
                    search(nx, ny, node.getChild(map[nx][ny]), depth + 1);
            }
        }
        pathWord.deleteCharAt(pathWord.length() - 1);
        check[x][y] = false;
    }

    static void makeString() {
        String s = pathWord.toString();
        if (longWord == null || longWord.length() < s.length())
            longWord = s;
        else if (longWord.length() == s.length() && longWord.compareToIgnoreCase(s) > 0)
            longWord = s;
        return;
    }
}

class TrieNode {
    boolean isRoot;
    boolean isLeaf;
    boolean isCheck;
    int childCnt;
    TrieNode[] child = new TrieNode[26];
    public TrieNode(boolean isRoot, boolean isLeaf) {
        this.isRoot = isRoot;
        this.isLeaf = isLeaf;
        this.childCnt = 0;
        this.isCheck = false;
    }

    boolean hasChild(char c) {
        if (childCnt == 0)
            return false;
        return child[c - 'A'] != null;
    }

    TrieNode getChild(char c) {
        return child[c - 'A'];
    }

    TrieNode insert(char c, boolean isFinish) {
        if (!hasChild(c)) {
            child[c - 'A'] = new TrieNode(false, false);
            childCnt++;
        }
        if (isFinish)
            child[c - 'A'].isLeaf = true;
        return child[c - 'A'];
    }
}
