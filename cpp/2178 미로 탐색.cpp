#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, m;
int a[101][101] = { 0, };
int dx[] = { -1,0,1,0 }; //시계방향
int dy[] = { 0,1,0,-1 };
int cnt[101][101] = { 0, };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	cnt[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) { //한 정점의 네방향 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (cnt[nx][ny] == 0 && a[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					cnt[nx][ny] = cnt[x][y] + 1;
				}
				else if (cnt[nx][ny] == 0) cnt[nx][ny] = -1;
			}
		}
	}
}

int main(void) {
	char b;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b;
			if (b == '1') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	bfs(0, 0);
	cout << cnt[n - 1][m - 1];
	return 0;
}
