#include<iostream>
#include<algorithm>
using namespace std;

int a[10001];

int main(void) {
	int n, k;
	int m = 0;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		a[k]++;
		m = max(k, m);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= a[i]; j++) {
			if (a[i] == 0) break;
			else printf("%d\n", i);
		}
	}
	return 0;
}
