#include<iostream>
using namespace std;
int a[1001][1001];
long long com(int m,int n) {
	if (a[m][n] != 0) return a[m][n];
	if (n == m || n == 0) return 1;
	else return a[m][n] = com(m - 1, n)%10007 + com(m - 1, n - 1)%10007;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	cout << com(n, m)%10007 << endl;
	return 0;
}
