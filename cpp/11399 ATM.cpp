#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	int n;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		ans += v[i] * (n - i);
	}
	cout << ans;
	return 0;
}
