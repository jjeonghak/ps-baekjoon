#include<iostream>
#include<algorithm>
using namespace std;
int a[10001];
int n, m;

bool p(int mid) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= mid) sum += a[i];
		else sum += mid;
	}
	if (sum <= m) return 1;
	else return 0;
}

int search(int le, int ri) {
	int ans;
	while (le<=ri) {
		int mid = (le + ri) / 2;
		if (p(mid)) {
			ans = mid;
			le = mid + 1;
		}
		else ri = mid - 1;
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int sum = 0,x=0;
	int le = 0;
	int ri = 100001;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		x = max(x, a[i]);
	}
	
	cin >> m;
	if (m >= sum) cout << x;
	else {
		cout << search(le, ri);
	}
	return 0;
}
