#include<iostream>
using namespace std;

int n, m;
int a[10];
bool c[10];

void sol(int k) { 
	if (k == m) { 
		for (int i = 0; i < m; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!c[i]) { 
			a[k] = i; 
			sol(k + 1);
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n >> m;
	sol(0); 
	return 0;
}
