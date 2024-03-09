#include<iostream>
#include<map>
using namespace std;

map<int,int> m1;

int main(void) {
	int n, m;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		m1[a] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		if (m1.find(a) != m1.end()) printf("1 ");
		else printf("0 ");
	}
	return 0;
}
