#include<iostream>
using namespace std;

int n;
int a[49];
bool c[49];
int sol[6];

void bt(int cnt, int start) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", sol[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i < n; i++) {
		if (!c[i]) {
			c[i] = true;
			sol[cnt] = a[i];
			cnt++;
			bt(cnt, i);
			cnt--;
			c[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		bt(0, 0);
		printf("\n");
	}
	return 0;
}
