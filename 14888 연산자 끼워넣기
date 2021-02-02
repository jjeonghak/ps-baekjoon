#include<iostream>
using namespace std;

int n;
int a[101];
int c[101];
int b[4];
int cnt;
int max1 = -1000000000;
int min1 = 1000000000;


void dfs(int x) {
	if (x == cnt) {
		int ans = a[0];
		for (int i = 0; i < cnt; i++) {
			if (c[i] == 0) {
				ans += a[i + 1];
			}
			else if (c[i] == 1) {
				ans -= a[i + 1];
			}
			else if (c[i] == 2) {
				ans *= a[i + 1];
			}
			else ans /= a[i + 1];
		}
		if (ans > max1) max1 = ans;
		if (ans < min1) min1 = ans;
		return;
	}
	for(int i=0;i<4;i++){
		if (b[i] != 0) {
			c[x] = i;
			b[i]--;
			dfs(x + 1);
			b[i]++;
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cnt = 0;
	for (int i = 0; i < 4; i++) {
		cin >> b[i];
		cnt += b[i];
	}
	dfs(0);
	cout << max1 << endl << min1;
	return 0;
}
