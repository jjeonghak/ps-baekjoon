#include<iostream>
using namespace std;

int n, m;
int a[10];
bool c[10];

void sol(int k) { 
	if (k == m+1) { 
		for (int i = 1; i < m+1; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!c[i]&&a[k-1]<=i) { 
			a[k] = i; 
			sol(k + 1);
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n >> m;
	sol(1); 
	return 0;
}
