#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void) {
	int n, m;
	string a;
	map<string, int> x1; //map을 
	map<int, string>x2;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		x1[a] = i; 
		x2[i] = a;
	}
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a[0] >= '1' && a[0] <= '9') {
			int b = stoi(a);
			cout << x2.find(b)->second<< "\n"; //endl 쓰면 시간초과
		}
		else cout << x1.find(a)->second << "\n";
	}
	return 0;
}
