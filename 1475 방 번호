#include<iostream>
using namespace std;

int b[10];

int main(void) {
	string a;
	int ans = 0;
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		int temp = a[i] - '0';
		if (temp == 9) {
			b[6]++;
		}
		else b[temp]++;
	}
	if (b[6] % 2 != 0) b[6] = b[6] / 2 + 1;
	else b[6] /= 2;
	for (int i = 0; i < 9; i++) {
		if (ans < b[i]) ans = b[i];
	}
	cout << ans;
	return 0;
}
