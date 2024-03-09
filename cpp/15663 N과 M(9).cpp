#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int a[10], b[10];
int n, m, cnt;
bool c[10];
int d[10001];

void sol(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < cnt; i++) {
		bool s = true;
		if (!c[i]) {
			b[k] = a[i];
			if (d[a[i]] != 0) {
				d[a[i]]--;
				s = false;
			}
			else c[i] = true;
			sol(k + 1);
			c[i] = false;
			if(!s) d[a[i]]++; 
		}
	}
}

int main(void) {
	int x;
	map<int, bool> m1;
	cin >> n >> m;
	cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (m1.find(x) != m1.end()) d[x]++; //반복가능 여부판단
		else {
			a[cnt] = x;
			m1.insert({ x,true });
			cnt++;
		}
	}
	sort(a, a + cnt);
	sol(0);
	return 0;
}
