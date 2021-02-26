#include<iostream>
using namespace std;

int map[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int breaked[101][101];
bool visit[101][101];
int n, m;

void dfs(int x, int y, int cnt) {
	if (cnt > breaked[m - 1][n - 1]) return; //현재 부순 벽이 최종값보다 큰 경우
	if (breaked[x][y] <= cnt) return; //현재 부순 벽이 기록된 값보다 큰 경우
	else breaked[x][y] = cnt; 
	if (x == m - 1 && y == n - 1) return; //
	for (int i = 0; i < 4; i++) {
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (!visit[newx][newy] && newx >= 0 && newx <= m - 1 && newy >= 0 && newy <= n - 1) {
			visit[newx][newy] = true;
			dfs(newx, newy, cnt + map[newx][newy]);
			visit[newx][newy] = false;
		}
	}
}


int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char a;
			cin >> a;
			map[i][j] = a - '0';
			breaked[i][j] = 1000000;
		}
	}
	visit[0][0] = true;
	dfs(0, 0, 0);
	cout << breaked[m - 1][n - 1];
	return 0;
}
