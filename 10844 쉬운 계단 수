// 일반적 DP
#include<iostream> 
#define MM 1000000000
using namespace std;

int dp[101][11];

int main(void) {
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][10] = 0;
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MM;
		}
	}
	for (int i = 1; i <= 9; i++) {
		ans = (ans + dp[n][i]) % MM;
	}
	cout << ans;
	return 0;
}

// 슬라이딩 윈도우 기법
#include<iostream> 
#define MM 1000000000
using namespace std;

int a[2][12];

int main(void) {
	int n, ans = 9;
	cin >> n;
	for (int i = 2; i < 11; i++) {
		a[1][i]=1;
	}
	for (int i = 2; i <= n; i++) {
		ans = 0;
		for (int j = 1; j < 11; j++) {
			a[i % 2][j] = a[(i - 1) % 2][j - 1] % MM + a[(i - 1) % 2][j + 1] % MM;
			ans = (ans + a[i % 2][j]) % MM;
		}
	}
	cout << ans;
	return 0;
}
