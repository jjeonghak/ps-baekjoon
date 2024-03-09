#include<iostream>
using namespace std;

int n;
long long dis[100001];
long long pri[100001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> dis[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> pri[i];
	}
	long long cnt = 0, ans = 0;
	long long nowpri=1000000001;
	while (cnt != n-1) {
		if (nowpri > pri[cnt]) nowpri = pri[cnt];
		ans += nowpri * dis[cnt];
		cnt++;
	}
	cout << ans;
	return 0;
}
