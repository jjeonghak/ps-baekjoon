#include<iostream>
using namespace std;
int a[1001];
int dp[1001];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = a[i]; //dp는 최종 합이므로 자기 자신도 더해야함
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				if (max < dp[j]) max = dp[j];
			}
		}
		dp[i] += max;
		if (ans < dp[i]) ans = dp[i];
	}
	cout << ans;
	return 0;
}
