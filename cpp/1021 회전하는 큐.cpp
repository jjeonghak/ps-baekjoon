#include<iostream>
#include<deque>
using namespace std;

int main(void) {
	int m, n, res = 0;
	deque<int>dq;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		int a;
		cin >> a;
		int k;
		for (int i = 1; i <= dq.size(); i++) {
			if (dq[i] == a) {
				k = i; // 큐에서 a의 위치
				break;
			}
		}
		if (k < dq.size() - k) { 
			while (1) {
				if (dq.front() == a) {
					dq.pop_front();
					break;
				}
				dq.push_back(dq.front());
				dq.pop_front();
				res++;
			}
		}
		else {
			while (1) {
				if (dq.front() == a) {
					dq.pop_front();
					break;
				}
				dq.push_front(dq.back());
				dq.pop_back();
				res++;
			}
		}
	}	
	cout << res;
	return 0;
}
