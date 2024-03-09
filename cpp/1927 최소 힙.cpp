#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> pq;

int main(void) {
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a > 0) pq.push(-a);
		else if (!pq.empty()) {
			printf("%d\n",-1*pq.top());
			pq.pop();
		}
		else printf("0\n");
	}
	return 0;
}
