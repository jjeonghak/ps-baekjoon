#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> pq1;
priority_queue<int> pq2;

int main(void) {
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a > 0) pq1.push(-a); //양수는 작은 것부터
		else if (a < 0) pq2.push(a); //음수는 큰 것부터, 절댓값이 작은 순이므로
		else {
			if (pq1.empty() && pq2.empty()) printf("0\n");
			else if (pq1.empty()) {
				printf("%d\n", 1 * pq2.top());
				pq2.pop();
			}
			else if (pq2.empty()) {
				printf("%d\n", -1 * pq1.top());
				pq1.pop();
			}
			else if (abs(pq1.top()) < abs(pq2.top())) {
				printf("%d\n", -1 * pq1.top());
				pq1.pop();
			}
			else {
				printf("%d\n", 1 * pq2.top());
				pq2.pop();
			}
		}
	}
	return 0;
}
