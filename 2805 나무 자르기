#include<iostream>
#include<algorithm>
using namespace std;
long long m;
long long a[1000001];
int n;

bool p(long long mid) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > mid) sum += (a[i] - mid);
	}
	if (sum >= m) return 1;
	else return 0;
}

int main(void) {
	long long ri = 0;
	long long le = 0;
	long long ans;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ri = max(ri, a[i]);
	}
	while (le <= ri) {
		long long mid = (le + ri) / 2;
		if (p(mid)) {
			ans = mid;
			le = mid + 1;
		}
		else ri = mid - 1;
	}
	cout << ans;
	return 0;
}
