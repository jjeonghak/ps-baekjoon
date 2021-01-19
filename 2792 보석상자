#include<iostream>
using namespace std;
long long a[300001];
int main(void) {
	long long n, m;
	long long max = 0;
	long long k = 1000000000;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		if (max < a[i]) max = a[i];
	}
	long long le = 1, ri = max;
	while (le <= ri) {
		long long mid = (le + ri) / 2;
		long long temp = 0;
		for (int i = 0; i < m; i++) {
			temp += a[i] / mid;
			if (a[i] % mid != 0) temp++;
		}
		if (temp <= n) {
			ri = mid - 1;
			if (mid < k) k = mid;
		}
		else le = mid + 1;
	}
	cout << k;
	return 0;
}
