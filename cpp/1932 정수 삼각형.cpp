#include<iostream>
#include<algorithm>
using namespace std;

int a[501][501];
int dp[501][501];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + a[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + a[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}
