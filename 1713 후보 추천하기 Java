import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        List<Integer> candidate = new ArrayList<>();
        int[] check = new int[101];
        int[] cnt = new int[101];

        for (int i=1; i<=k; i++) {
            int index = sc.nextInt();
            if (check[index] == 0) {
                if (candidate.size() == n) {
                    int minIndex = candidate.get(0);
                    int minCnt = cnt[minIndex];
                    int candidateIndex = 0;

                    for (int j=1; j<candidate.size(); j++) {
                        if (cnt[candidate.get(j)] <= minCnt) {
                            if (cnt[candidate.get(j)] == minCnt && check[candidate.get(j)] > check[minIndex])
                                continue;
                            minIndex = candidate.get(j);
                            minCnt = cnt[minIndex];
                            candidateIndex = j;
                        }
                    }
                    candidate.remove(candidateIndex);
                    cnt[minIndex] = 0;
                    check[minIndex] = 0;
                }

                check[index] = i;
                cnt[index] = 1;
                candidate.add(index);
            }
            else
                cnt[index]++;
        }

        Collections.sort(candidate);
        candidate.forEach(c -> System.out.print(c + " "));
    }
}
