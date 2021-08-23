#include<iostream>
using namespace std;

int m, n;
int map[501][501];
int dp[501][501];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int dfs(int y, int x) {
	if (y == 0 && x == 0) return 1;
	else if(dp[y][x] == -1){
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < m && ny >= 0 && nx < n && nx >= 0) {
				if (map[y][x] < map[ny][nx]) {
					dp[y][x] += dfs(ny, nx);
				}
			}
		}
	}
	return dp[y][x];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for(int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	cout << dfs(m - 1, n - 1) << '\n';
	return 0;
}
