#include<iostream>
using namespace std;
int map[130][130];
int cntb, cntw;

void sol(int x, int y, int k) {
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if (map[i][j] != map[x][y]) {
				sol(x, y, k / 2);
				sol(x + k / 2, y, k / 2);
				sol(x, y + k / 2, k / 2);
				sol(x + k / 2, y + k / 2, k / 2);
				return;
			}
		}
	}
	if (map[x][y] == 0) cntw++;
	else if (map[x][y] == 1) cntb++;
	return;
}

int main(void) {
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	cntb = 0;
	cntw = 0;
	sol(0, 0, n);
	cout << cntw << endl << cntb;
	return 0;
}
