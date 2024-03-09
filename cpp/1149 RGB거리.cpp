#include<iostream>
#include<algorithm>
using namespace std;

int a[1001][3];
int dp[1001][3];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	int j = 0;
	while (1) {
		if (j == n) break;
		dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + a[j][0];
		dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + a[j][1];
		dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + a[j][2];
		j++;
	}
	int ans = min(dp[n - 1][0], dp[n - 1][1]);
	ans = min(ans, dp[n - 1][2]);
	cout << ans;
	return 0;
}
