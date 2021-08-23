#include<iostream>
using namespace std;

int main(void) {
	int n, cnt;
	long long pre = 0, ans = 1, temp;

	cin >> n;
	cnt = n;
	if (n == 0) cout << 0;
	else {
		while (--cnt) {
			temp = ans;
			ans = temp + pre;
			pre = temp;
		}
		cout << ans;
	}
	return 0;
}
