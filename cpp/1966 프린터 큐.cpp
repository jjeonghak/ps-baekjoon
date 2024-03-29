#include<cstdio>
#include<queue>
using namespace std;

int main(void) {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int n, m;
		int cnt = 0;
		scanf("%d %d", &n, &m);
		for (int j = 0; j < n; j++) {
			int a;
			scanf("%d", &a);
			q.push({ j, a }); //pair값 삽입
			pq.push(a);
		}
		while (!q.empty()) {
			int ind = q.front().first;  //현재 값 정보
			int pri = q.front().second;
			q.pop();

			if (pq.top() == pri) { //현재 우선순위와 우선순위 순서가 일치할 경우
				pq.pop();
				cnt++;
				if (ind == m) { //현재 순서가 구하고자 하는 순서인 경우
					printf("%d\n", cnt);
					break;
				}
			}
			else q.push({ ind,pri }); //우선순위가 낮아 뒤로 보냄			
		}
	}
	return 0;
}
