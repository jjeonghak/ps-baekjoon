import java.io.*;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = 0;
        boolean finish = false;

        while (true) {
            t++;
            boolean input = true, check = false;
            Set<Long> vSet = new HashSet<>();
            Set<Long> uSet = new HashSet<>();
            long cnt = 0;

            while (input) {
                StringTokenizer st = new StringTokenizer(br.readLine());

                while (st.hasMoreTokens()) {
                    long u = Long.parseLong(st.nextToken());
                    long v = Long.parseLong(st.nextToken());

                    if (u == 0 && v == 0) {
                        input = false;
                        break;
                    } else if (u < 0 && v < 0) {
                        finish = true;
                        input = false;
                        break;
                    } else {
                        if (vSet.contains(v))
                            check = true;
                        else
                            vSet.add(v);
                        uSet.add(u);
                    }
                }
            }
            Iterator<Long> iter = uSet.iterator();
            while (iter.hasNext() && !check) {
                Long index = iter.next();
                if (!vSet.contains(index))
                    cnt++;
                if (cnt == 2) {
                    check = true;
                    break;
                }
            }
            if (uSet.size() != 0 && cnt != 1)
                check = true;
            if (finish)
                break;
            bw.write("Case " + t + " is ");
            if (check)
                bw.write("not ");
            bw.write("a tree.\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
