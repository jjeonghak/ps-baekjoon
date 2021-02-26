#include<iostream>
using namespace std;

int r, c;
char map[21][21];
bool visit[21][21];
bool al[26];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int ans;

void bt(int x, int y,int cnt) {
	if (cnt > ans) ans = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visit[nx][ny] && nx >= 0 && nx < r && ny >= 0 && ny < c) {
			if (!al[map[nx][ny]-'A']) {
				al[map[nx][ny] - 'A'] = true;
				visit[nx][ny] = true;
				bt(nx, ny, cnt + 1);
				al[map[nx][ny] - 'A'] = false;
				visit[nx][ny] = false;
			}
		}
	}
	return;
}

int main(void) {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	visit[0][0] = true;
	al[map[0][0] - 'A'] = true;
	bt(0, 0, 1);
	cout << ans;
	return 0;
}
