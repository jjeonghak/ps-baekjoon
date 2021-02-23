#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;
vector<int> v1;

bool compare(int a, int b) {
	if (a <= b) return false;
	else return true;
}

int main(void) {
	int n;
	int ans = 0;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1) ans++; //1은 더하는 것이 더 
		else if (a > 0) v.push_back(a);
		else v1.push_back(a);
	}
	sort(v.begin(), v.end(),compare);
	sort(v1.begin(), v1.end());

	if (!v.empty()) {
		if (v.size() % 2 == 1) {
			v.push_back(1);
			for (int i = 0; i < v.size() - 1; i += 2) {
				ans += (v[i] * v[i + 1]);
			}
		}
		else {
			for (int i = 0; i < v.size(); i += 2) {
				ans += (v[i] * v[i + 1]);
			}
		}
	}
	if (!v1.empty()) {
		if (v1.size() % 2 == 1) {
			v1.push_back(1);
			for (int i = 0; i < v1.size() - 1; i += 2) {
				ans += (v1[i] * v1[i + 1]);
			}
		}
		else {
			for (int i = 0; i < v1.size(); i += 2) {
				ans += (v1[i] * v1[i + 1]);
			}
		}
	}
	cout << ans;
	return 0;
}
