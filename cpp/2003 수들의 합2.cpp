#include<iostream>
using namespace std;

int a[10001];

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i = 0, j = 0, ans = 0;
	while (1) {
		int sum = 0;
		for (int k = j; k <= i; k++) {
			sum += a[k];
		}
		if (sum < m) {
			if (i == n-1) break;
			i++;
		}
		else if (sum > m) {
			if (i == j) {
				if (i == n-1) break;
				i++;
			}
			else j++;
		}
		else {
			ans++;
			if (i == j) {
				if (i == n-1) break;
				i++;
			}
			else j++;
		}
	}
	cout << ans;
	return 0;
}
