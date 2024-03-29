#include<iostream>
using namespace std;

int n;
int a[21][21];
bool c[22];
int ans = 1000000000;

void dfs(int x, int k) {
	if (x == n / 2) {
		int st = 0, lt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (c[i] && c[j]) st += a[i][j];
				if (!c[i] && !c[j]) lt += a[i][j];
			}
		}
		int temp = abs(st - lt);
		if (ans > temp) ans = temp;
		return;
	}
	for (int i = k; i < n; i++) {
        c[i] = true;
		dfs(x + 1, k + 1);
		c[i] = false;
	}
}

int main(void) {
	int s;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	dfs(0, 1);
	cout << ans;
	return 0;
}
