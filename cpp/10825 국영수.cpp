#include<iostream>
#include<algorithm>
using namespace std;

pair<pair<string, int>, pair<int, int>> p[100001];

bool compare(pair<pair<string, int>, pair<int, int>> a, pair<pair<string, int>, pair<int, int>> b){
	if (a.first.second > b.first.second) return true;
	else if (a.first.second == b.first.second) { //아닌 경우 중 같을때 처리필수
		if (a.second.first < b.second.first) return true;
		else if (a.second.first == b.second.first) {
			if (a.second.second > b.second.second) return true;
			else if (a.second.second == b.second.second) {
				if (a.first.first < b.first.first) return true;
			}
		}
	}
	return false;
}
int main(void) {
	int n, x, y, z;
	string b;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b >> x >> y >> z;
		p[i].first.first = b;
		p[i].first.second = x;
		p[i].second.first = y;
		p[i].second.second = z;
	}
	sort(p, p + n,compare);
	for (int i = 0; i < n; i++) {
		cout << p[i].first.first << "\n"; //시간초과로 인한 "\n"
	}
	return 0;
}
