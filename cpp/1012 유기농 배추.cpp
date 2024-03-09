#include<iostream>
using namespace std;
int m, n;

int a[51][51] = { 0, };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int x, int y) {
	if (a[x][y] == 1) {
		a[x][y] = 0; //이동한 지점 0초기화
		for (int i = 0; i < 4; i++) { //네방향으로 이동하며 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) dfs(nx, ny);
		}
	}
}

int main(void) {
	int t, k, x, y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			a[x][y] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1) { 
					dfs(i, j); //한번 실행될때마다 1주변에 모여있는 1을 모두 0으로 초기화
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
