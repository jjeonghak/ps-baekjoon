#include<iostream>
using namespace std;

int arr[301][301];
int dp[91000];

int main(void) {
	int t, i, j, x, y, sum, n, m, k;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[(i - 1) * m + j] = dp[(i - 1) * m + j - 1] + arr[i][j];
		}
	}
	cin >> k;
	for (t = 0; t < k; t++) {
		cin >> x >> y >> i >> j;
		int ans = 0;
		for (int l = x; l <= i; l++) {
			ans += (dp[(l - 1) * m + j] - dp[(l - 1) * m + y - 1]);
		}
		cout << ans << "\n";
	}
	return 0;
}
