import java.util.*;

public class Main {

    public static class Pair {
        public String n;
        public int cnt;

        public Pair(String n, int cnt) {
            this.n = n;
            this.cnt = cnt;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair pair = (Pair) o;
            return cnt == pair.cnt && Objects.equals(n, pair.n);
        }

        @Override
        public int hashCode() {
            return Objects.hash(n, cnt);
        }
    }
    
    public static int answer;
    public static HashSet<Pair> set = new HashSet<>();

    public static void swapArray(char[] n, int i, int j) {
        char temp = n[i];
        n[i] = n[j];
        n[j] = temp;
        return;
    }
    public static void dfs(int cnt, char[] n, int m) {
        if (cnt == 0) {
            int result = Integer.parseInt(String.valueOf(n));
            if (answer < result) answer = result;
            return;
        }
        for (int i=0; i<m; i++) {
            for (int j=i+1; j<m; j++) {
                if (i==0 && n[j] == '0')
                    continue;

                swapArray(n, i, j);
                Pair newPair = new Pair(String.valueOf(n), cnt);
                if (!set.contains(newPair)) {
                    set.add(newPair);
                    dfs(cnt - 1, n, m);
                }
                swapArray(n, i, j);
            }
        }
        return;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.next();
        int k = sc.nextInt();
        char[] nArray = n.toCharArray();
        answer = -1;
        dfs(k, nArray, n.length());
        System.out.println(answer);
    }
}
