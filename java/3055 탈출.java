import java.util.*;

public class Main {

    static class location {
        public int x;
        public int y;
        public int flag;
        public int cnt;

        public void setting(int x, int y, int f) {
            this.x = x;
            this.y = y;
            this.flag = f;
            this.cnt = 0;
        }

        public location(int x, int y, int f, int c) {
            this.x = x;
            this.y = y;
            this.flag = f;
            this.cnt = c;
        }
    }

    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};
    static int[][] map;
    static int[][] check;
    static location start = new location(0, 0, 0, 0);
    static List<location> water = new ArrayList<>();

    public static int bfs(int r, int c) {
        Queue<location> q = new LinkedList<>();
        if (!water.isEmpty())
            water.stream().iterator().forEachRemaining(w -> q.offer(w));
        q.offer(start);
        check[start.x][start.y] = 1;
        while (!q.isEmpty()) {
            location now = q.peek();
            q.poll();
            int x = now.x;
            int y = now.y;

            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx>=0 && nx<r && ny>=0 && ny<c && map[nx][ny] != 1) {
                    if (map[nx][ny] == 0) {
                        if (now.flag == 1) {
                            q.offer(new location(nx, ny, 1, now.cnt));
                            map[nx][ny] = 1;
                        } else if (now.flag == 0 && check[nx][ny] == 0) {
                            q.offer(new location(nx, ny, 0, now.cnt + 1));
                            check[nx][ny] = 1;
                        }
                    }
                    else if (map[nx][ny] == -1 && now.flag == 0)
                        return now.cnt + 1;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        map = new int[r][c];
        check = new int[r][c];

        for (int i=0; i<r; i++) {
            String s = sc.next();
            for (int j = 0; j < c; j++) {
                char ch = s.charAt(j);
                if (ch == 'S') {
                    start.setting(i, j, 0);
                    map[i][j] = 0;
                }
                else if (ch == 'D')
                    map[i][j] = -1;
                else if (ch == '*') {
                    map[i][j] = 1;
                    water.add(new location(i, j, 1, 0));
                }
                else if (ch == 'X')
                    map[i][j] = 2;
                else
                    map[i][j] = 0;
            }
        }

        int result = bfs(r, c);
        if (result != -1)
            System.out.println(result + "");
        else
            System.out.println("KAKTUS");
        sc.close();
    }
}
