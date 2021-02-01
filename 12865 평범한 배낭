#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[101][100001];

int main(void) {
	int n, k, a, b;
	vector<pair<int, int>> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	for (int i = 0; i < n; i++) { //짐의 갯수
		for (int j = 0; j <= k; j++) { //배낭에 들어가는 무게
			if (i == 0) {
				if (v[i].first <= j) dp[i][j] = v[i].second;
				continue;
			}
			if (v[i].first <= j) dp[i][j] = max(dp[i - 1][j], v[i].second + dp[i - 1][j - v[i].first]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n - 1][k];
	return 0;
}
