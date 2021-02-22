#include<iostream>
#include<cstring>
using namespace std;

int map[51][51];
bool c[51][51];
int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dy[8] = { 1,-1,1,0,-1,1,0 ,-1 };

void dfs(int x, int y,int h, int w) {
	c[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (!c[newx][newy] && map[newx][newy] == 1) {
			if (newx > 0 && newx <= h && newy > 0 && newy <= w) dfs(newx, newy, h, w);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		int w, h;
		memset(c, false, sizeof(c));
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
			}
		}
		int cnt = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (!c[i][j] && map[i][j] == 1) {
					dfs(i, j, h, w);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
