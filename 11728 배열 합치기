#include<iostream>
using namespace std;

int a[1000001];
int b[1000001];
int ans[1000001];
int n, m;

void merge() {
	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
		if (a[i] <= b[j]) ans[k++] = a[i++];
		else ans[k++] = b[j++];
	}
	while (i < n) ans[k++] = a[i++];
	while (j < m) ans[k++] = b[j++];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	merge();
	for (int i = 0; i < n + m; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}
