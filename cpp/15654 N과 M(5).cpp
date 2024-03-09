#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int a[10];
int b[10];
bool c[10];

void sol(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!c[i]) {
			b[k] = a[i];
			c[i] = true;
			sol(k + 1);
			c[i] = false;
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];                                                       
	}
	sort(a, a + n);
	sol(0);
	return 0;
}
