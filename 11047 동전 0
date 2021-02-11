#include<iostream>
using namespace std;

int a[11];

int main(void) {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i = n - 1;
	int cnt = 0;
	while (k != 0) {
		if (a[i] > k) i--;
		else{
			k -= a[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
