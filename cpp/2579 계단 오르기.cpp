#include<iostream>
#include<algorithm>
using namespace std;

int dp[305];
int a[305];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0] = a[0];
	dp[1] = max(a[0] + a[1], a[1]);
	dp[2] = max(a[0] + a[2], a[1] + a[2]);

	for (int i=3; i < n ; i++) {
		dp[i] = max(dp[i - 3] + a[i - 1] + a[i], dp[i - 2] + a[i]); 
	}
	cout << dp[n -1];
	return 0;
}
