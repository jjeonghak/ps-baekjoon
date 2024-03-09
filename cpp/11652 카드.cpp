#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

map<long long, int>m;
vector<pair<long long, int>> v;

bool compare(pair<long long, int> a, pair<long long, int>b) {
	if (a.second > b.second) return true;
	else if (a.second == b.second) {
		if (a.first < b.first) return true;
		else return false;
	}
	return false;
}

int main(void) {
	int n;
	long long a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (m.find(a) != m.end()) m.find(a)->second++;
		else m[a] = 1;
	}
	map<long long, int>::iterator j;
	for (j = m.begin(); j != m.end(); j++) {
		v.push_back(*j);
	}
	sort(v.begin(),v.end(), compare);
	cout << v.front().first;
	return 0;
}
