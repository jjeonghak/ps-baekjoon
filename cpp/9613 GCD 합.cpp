#include<iostream>
using namespace std;

int a[101];

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a; 
}

int main(void) {
	int t, n;
	long long ans;
	cin >> t;
	for (int i = 0; i < t; i++) {
		ans = 0; 
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				ans += gcd(a[j], a[k]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
