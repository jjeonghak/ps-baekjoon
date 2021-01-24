#include<iostream>
#include<algorithm>
using namespace std;

int a[101];

int main(void) {
	int n, m;
	int ans = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int temp = 0;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			for (int k = j + 1; k <= n; k++) {
				temp = a[k] + a[j] + a[i];
				if (temp <= m) {
					ans = max(ans, temp);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
