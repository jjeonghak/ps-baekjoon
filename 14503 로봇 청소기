#include <iostream>
using namespace std;

int n, m, cnt = 0;
int map[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int backDx[4] = { 1, 0, -1, 0 };
int backDy[4] = { 0, -1, 0, 1 };

void dfs(int x, int y, int d) {
	int k;
	if (map[x][y] == 0) {
		cnt++;
		map[x][y] = 2;
	}
	for (k = d - 1; k > d - 5; k--) {
		int nk = (k + 4) % 4;
		int nx = x + dx[nk];
		int ny = y + dy[nk];
		if (ny<0 || ny>m - 1 || nx<0 || nx>n - 1) continue;
		if (map[nx][ny] == 0) {
			dfs(nx, ny, nk);
			return;
		}
	}
	if (map[x + backDx[d]][y + backDy[d]] == 1) return;
	else dfs(x + backDx[d], y + backDy[d], d);
}

int main(void) {
    int r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    dfs(r, c, d);
    cout << cnt;
    return 0;
}
