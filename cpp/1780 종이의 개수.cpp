#include<iostream>
using namespace std;

int map[3000][3000];
int n;
int ans, ans1, ans2;

void sol(int x, int y, int m) {
	if(m!=1) {
		for (int i = x; i < x + m; i++) {
			for (int j = y; j < y + m; j++) {
				if (map[x][y] != map[i][j]) {
					int k = m / 3;
					sol(x, y, k);
					sol(x + k, y, k);
					sol(x, y + k, k);
					sol(x + k, y + k, k);
					sol(x + 2 * k, y, k);
					sol(x, y + 2 * k, k);
					sol(x + 2 * k, y + k, k);
					sol(x + k, y + 2 * k, k);
					sol(x + 2 * k, y + 2 * k, k);
					return;
				}
			}
		}
	}
	if (map[x][y] == 0) ans++;
	else if (map[x][y] == 1) ans1++;
	else if (map[x][y] == -1) ans2++;
	return;
}


int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	ans = 0;
	ans1 = 0;
	ans2 = 0;
	sol(0, 0, n);
	cout << ans2 << endl << ans << endl << ans1;
	return 0;
}
