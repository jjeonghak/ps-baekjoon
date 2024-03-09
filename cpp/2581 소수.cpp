#include<iostream>
using namespace std;

int main(void) {
	int m, n;
	int sum = 0;
	int ans = 0;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		int a = 1;
		if (i == 1) continue;
		else {
			for (int j = 2; j < i; j++) {
				if (i % j == 0) a = 0;
			}
			if (a == 1) {
				if (sum == 0) ans = i;
				sum += i;
			}
		}
	}
	if (ans != 0)cout << sum << endl << ans;
	else cout << "-1";
	return 0;
}
