#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int map[101][101];
bool c[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };


void dfs(int h,int x,int y) {
	c[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!c[nx][ny] && map[nx][ny] >= h) dfs(h, nx, ny);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int low = 101, hi = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (hi < map[i][j]) hi = map[i][j];
			if (low > map[i][j]) low = map[i][j];
		}
	}
	int ans = 0;
	int cnt = 0;
	int h = low;
	while (h <= hi) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!c[i][j] && map[i][j] >= h) {
					dfs(h, i, j);
					cnt++;
				}
			}
		}
		memset(c, 0, sizeof(c));
		ans = max(ans, cnt);
		cnt = 0;
		h++;
	}
	cout << ans;
	return 0;
}
