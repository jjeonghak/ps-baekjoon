#include<iostream>
#include<algorithm>
using namespace std;

int a[1001];
int b[1001];
int dps[1001];
int dpb[1001];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		b[i] = a[n - 1 - i];
	}
	for (int i = 0; i < n; i++) {
		int maxs = 0;
		int maxb = 0;
		for (int j = 0; j < n; j++) {
			if (a[i] > a[j]) {
				if (maxs < dps[j]) maxs = dps[j];
			}
			if (b[i] > b[j]) {
				if (maxb < dpb[j]) maxb = dpb[j];
			}
		}
		dps[i] = maxs + 1;
		dpb[i] = maxb + 1;
	}
	for (int i = 0; i < n; i++) {
		ans = max(ans, dps[i] + dpb[n - 1 - i] - 1);
	}
	cout << ans;
	return 0;
}
