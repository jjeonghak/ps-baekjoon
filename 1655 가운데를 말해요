#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> pq; //가운데 값을 포함하는 작은 값
priority_queue<int> pq1; //가운데 값보다 큰 값

int main(void) {
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
		if (pq.size() > pq1.size() + 1) { //한쪽의 크기가 커져 가운데 값이 아니게 
			pq1.push(-pq.top());
			pq.pop();
		}
		if (!pq.empty() && !pq1.empty() && pq.top() > -pq1.top()) { //가운데 값이 다음 값보다 큰 경우
			pq.push(-pq1.top()); //두 값을 바꿈 
			pq1.pop();
			pq1.push(-pq.top());
			pq.pop();
		}
		printf("%d\n", pq.top());
	}
	return 0;
}
