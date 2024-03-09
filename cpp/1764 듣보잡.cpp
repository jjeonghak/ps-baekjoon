#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

map<string, bool> k;
vector<string> v;

int main(void) {
	int n, m;
	string a;
	map<string, bool>::iterator l;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		k[a] = true;
	}
	for (int i = 0; i < m; i++) {
		cin >> a;
		l = k.find(a); //find()는 그 값을 찾았을 경우 그 반복자를, 아닐 경우 map.end()를 반환
		if (l!=k.end()) v.push_back(a);
	}
	sort(v.begin(), v.end());
	vector<string>::iterator j;
	cout << v.size() << endl;
	for (j = v.begin(); j != v.end(); j++) {
		cout << *j << endl;
	}
	return 0;
}
