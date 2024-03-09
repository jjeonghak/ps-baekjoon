#include<iostream>
#include<algorithm>
using namespace std;
int p[1002];
int dp[1002];

int sol(int m) {
	if (dp[m] != 0) return dp[m];
	else if (m == 1) return dp[m] = p[1];
	else { 
		int n = 0;
		for (int i = 1; i <= m/2; i++) {
			n = max(n, sol(m - i) + sol(i));
		}
		return dp[m] = max(n, p[m]);
	}
}

int main(void) {
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	cout << sol(n);
	return 0;
}
