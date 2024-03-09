#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> v;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int ans = 0, k = 0;
	while (!v.empty()) {
		k++;
		if (v.back() > ans) {
			ans = v.back();
			k = 1;
		}
		else if (v.back() * k > ans) ans = v.back() * k;
		v.pop_back();
	}
	cout << ans;
	return 0;
}
