#include<iostream>
#include<algorithm>
using namespace std;

int a[200001];
int n, c;

bool b(int dis) {
	int cnt = 1;
	int prev = a[0];
	for (int i = 1; i < n; i++) { //조건 만족하는지
		if (a[i] - prev >= dis) {
			cnt++;
			prev = a[i];
		}
	}
	if (cnt >= c) return true; //조건 만족
	else return false;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int le = 1, ri = a[n - 1] - a[0];
	int ans = 0;
	while (le <= ri) {
		int mid = (le + ri) / 2;
		if (b(mid)) {
			ans = max(ans, mid);
			le = mid + 1;
		}
		else ri = mid - 1;
	}
	cout << ans;
	return 0;
}
