#include<iostream>
#include<algorithm>
using namespace std;

int a[51][51];

int sol(int& x,int& y) {
	int sum = 0;
	int sum1 = 0;
	for (int i = 1; i <= 8; i++) { //첫칸을 1로 했을 경우
		for (int j = 1; j <= 8; j++) {
			if ((x+i) % 2 != 0) { //홀수 번째 줄
				if ((y+j) % 2 != 0 && a[x+i][y+j] == 0) sum++;
				else if ((y+j) % 2 == 0 && a[x+i][y+j] == 1) sum++;
			}
			else { //짝수 번째 줄
				if ((y+j) % 2 != 0 && a[x+i][y+j] == 1) sum++;
				else if ((y+j) % 2 == 0 && a[x+i][y+j] == 0) sum++;
			}
		}
	}
	for (int i = 1; i <= 8; i++) { //첫칸을 0로 했을 경우
		for (int j = 1; j <= 8; j++) {
			if ((x + i) % 2 == 0) { //짝수 번째 줄
				if ((y + j) % 2 != 0 && a[x + i][y + j] == 0) sum1++;
				else if ((y + j) % 2 == 0 && a[x + i][y + j] == 1) sum1++;
			}
			else { //홀수 번째 줄
				if ((y + j) % 2 != 0 && a[x + i][y + j] == 1) sum1++;
				else if ((y + j) % 2 == 0 && a[x + i][y + j] == 0) sum1++;
			}
		}
	}
	int temp = min(sum, sum1);
	return temp;
}

int main(void) {
	int m, n;
	char c;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c == 'W') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	int ans = 100000000;
	for (int k = 0; k <= m - 8; k++) {
		for (int l = 0; l <= n - 8; l++) {
			int tmep1 = sol(k, l);
			ans = min(ans, tmep1);
		}
	}
	cout << ans;
	return 0;
}
