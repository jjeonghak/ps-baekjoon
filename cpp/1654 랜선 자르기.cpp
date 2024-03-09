#include<iostream>
#include<algorithm>
using namespace std;
long long line[10000];
int n,m;

bool p(long long len) {
	int a = 0;
	for (int i = 0; i < n; i++) {
		a += line[i] / len;
	}
	if (a >= m) return 1;
	else return 0;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	long long b = 0;
	long long ri = 0;
	long long le = 1;
	for (int i = 0; i < n; i++) {
		cin >> line[i];
		ri = max(ri, line[i]);
	}

	while (le <= ri) {
		long long mid = (le + ri) / 2;
		if (p(mid)) { //조건을 만족하면 좀더 길이를 증가
			if (b < mid) b = mid;
			le = mid + 1;
		}
		else ri = mid - 1;
	}
	cout << b << endl;
	return 0;
}
