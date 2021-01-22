#include<iostream>
#include<algorithm>
using namespace std;

int a[100001][2];
int b[100001][2];

int main(void) {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> a[k][j];
			}
		}
		b[1][0] = a[1][0];
		b[1][1] = a[1][1];
		for (int i = 2; i <= n; i++) { 
			b[i][0] = max(b[i - 1][1], b[i - 2][1]) + a[i][0];
			b[i][1] = max(b[i - 1][0], b[i - 2][0]) + a[i][1];
		}
		cout << max(b[n][0], b[n][1])<<endl;
		for (int i = 0; i <= n; i++) { //사용했던 배열 초기화
			b[i][0] = 0;
			b[i][1] = 0;
		}
	}
	return 0;
}
