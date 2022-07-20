import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static class Pair implements Comparable<Pair> {
        public int m;
        public int v;

        public Pair(int m, int v) {
            this.m = m;
            this.v = v;
        }

        @Override
        public int compareTo(Pair o) {
            return m - o.m;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());


        PriorityQueue<Integer> pqM = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> pqK = new PriorityQueue<>();
        List<Pair> pairList = new ArrayList<>();

        for (int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            pairList.add(new Pair(m, v));
        }

        for (int i=0; i<k; i++) {
            int c = Integer.parseInt(br.readLine());
            pqK.offer(c);
        }
        long sum = 0;
        Collections.sort(pairList);
        for (int i=0; i<n; i++) {
            if (pqK.isEmpty()) {
                break;
            }
             while (!pqK.isEmpty() && pairList.get(i).m > pqK.peek()) {
                pqK.poll();
                if (!pqM.isEmpty()) {
                    sum += Long.valueOf(pqM.peek());
                    pqM.poll();
                }
            }
            pqM.offer(pairList.get(i).v);
        }
        while (!pqK.isEmpty()) {
            if (pqM.isEmpty()) {
                break;
            } else {
                sum += pqM.peek();
                pqM.poll();
                pqK.poll();
            }
        }
        System.out.println(sum);
    }
}
