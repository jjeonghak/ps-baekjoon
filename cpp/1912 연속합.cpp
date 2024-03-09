#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int n,a;
	int sum = 0;
	int ans = -1001;
	int allmin = -1001;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum += a;
		if (sum <= 0) {
			allmin = max(allmin, a);
			sum = 0;
		}
		else {
			ans = max(ans, sum);
		}
	}
	if (ans > 0) cout << ans;
	else cout << allmin;
	return 0;
}
