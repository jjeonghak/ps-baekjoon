#include<iostream>
using namespace std;

int map[22][22];
int moving[1001];
int a[4];
int b[4];

int main(void) {
	int n, m, x, y, k;
	int dx = 0, dy = 0;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> moving[i];
	}
	for (int i = 0; i < k; i++) {
		if (moving[i] == 1) {
			if (y < m - 1) {
				y++;
				dy++;
				if (dy > 3) dy = 0;
				if (map[x][y] != 0) {
					b[dy] = map[x][y];
					map[x][y] = 0;
				}
				else map[x][y] = b[dy];
				a[dx] = b[dy];
				a[(dx + 2) % 4] = b[(dy + 2) % 4];
				printf("%d\n", b[(dy + 2) % 4]);
			}
		}
		else if (moving[i] == 2) {
			if (y > 0) {
				y--;
				dy--;
				if (dy < 0) dy = 3;
				if (map[x][y] != 0) {
					b[dy] = map[x][y];
					map[x][y] = 0;
				}
				else map[x][y] = b[dy];
				a[dx] = b[dy];
				a[(dx + 2) % 4] = b[(dy + 2) % 4];
				printf("%d\n", b[(dy + 2) % 4]);
			}
		}
		else if (moving[i] == 3) {			
			if (x > 0) {
				x--;
				dx--;
				if (dx < 0) dx = 3;
				if (map[x][y] != 0) {
					a[dx] = map[x][y];
					map[x][y] = 0;
				}
				else map[x][y] = a[dx];
				b[dy] = a[dx];
				b[(dy + 2) % 4] = a[(dx + 2) % 4];
				printf("%d\n", a[(dx + 2) % 4]);
			}
		}
		else if(moving[i] == 4) {
			if (x < n -1) {
				x++;
				dx++;
				if (dx > 3) dx = 0;
				if (map[x][y] != 0) {
					a[dx] = map[x][y];
					map[x][y] = 0;
				}
				else map[x][y] = a[dx];
				b[dy] = a[dx];
				b[(dy + 2) % 4] = a[(dx + 2) % 4];
				printf("%d\n", a[(dx + 2) % 4]);
			}
		}
	}
	return 0;
}

