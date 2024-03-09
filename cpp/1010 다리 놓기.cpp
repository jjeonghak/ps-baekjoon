#include<iostream>
using namespace std;
int a[31][31];
long long com(int m,int n) {
	if (a[m][n] != 0) return a[m][n];
	if (n == m || n == 0) return 1;
	else return a[m][n] = com(m - 1, n) + com(m - 1, n - 1);
}

int main(void) {
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << com(m, n) << endl;
	}
	return 0;
}
