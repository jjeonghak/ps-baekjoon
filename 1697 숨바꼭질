#include<iostream>
#include<queue>
using namespace std;

queue<int> q; //실행순서예약
bool c[100001];

int main(void) {
	int n, k, ans=0;
	cin >> n >> k;
	q.push(n);
	int l = 1;
	while (!q.empty()) {
		int cnt = 0;
		for (int i = 0; i < l; i++) {
			int x = q.front();
			q. pop();
			if (x == k) {
				cout << ans;
				return 0;
			}
			c[x] = true;
			if (x + 1 <= 100001 && !c[x + 1]) {
				q.push(x + 1);
				cnt++;
			}
			if (x -1 >= 0 && !c[x - 1]) {
				q.push(x - 1);
				cnt++;
			}
			if (x *2 <= 100001 && !c[2*x]) {
				q.push(2*x);
				cnt++;
			}
		}
		l = cnt;
		if (cnt!=0) ans++; //실행 1회 
	}
}
