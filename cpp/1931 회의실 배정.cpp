#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<long long, long long>a, pair<long long, long long>b) {
	if (a.second < b.second) return false;
	else if (a.second == b.second) {
		if (a.first < b.first) return false;
		else if (a.first == b.first) return false;
		else return true;
	}
	return true;
}

int main(void) {
	int n;
	vector<pair<long long, long long>>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), compare);
	int cnt = 0;
	long long done = -1;
	while (!v.empty()) {
		if (done > v.back().first) v.pop_back();
		else {
			done = v.back().second;
			cnt++;
			v.pop_back();
		}
	}
	cout << cnt;
	return 0;
}
