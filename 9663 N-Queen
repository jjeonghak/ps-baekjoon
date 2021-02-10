#include<iostream>
using namespace std;

int map[15][15];
int n, cnt, ans;

void bt(int start) {
	if (cnt == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (map[start][i]==0) {
			cnt++;
			int k = 1;
			for (int x = 0; x < n; x++) {
				map[x][i]++;
				if (x > start) {
					if (i - k >= 0) map[x][i - k]++;
					if (i + k < n) map[x][i + k]++;
					k++;
				}
				
			}
			bt(start + 1);
			cnt--;
			k = 1;
			for (int x = 0; x < n; x++) {
				map[x][i]--;
				if (x > start) {
					if (i - k >= 0) map[x][i - k]--;
					if (i + k < n) map[x][i + k]--;
					k++;
				}
			}
		}
	}
}

int main(void) {
	cin >> n;
	bt(0);
	cout << ans;
	return 0;
}
