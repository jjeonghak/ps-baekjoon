#include<iostream>
using namespace std;

int main(void) {
	int n, l;
	cin >> n >> l;
	int k = 0;
	int ans;
	bool b = true;
	for (int i = 0; i <= l-1; i++) {
		k += i;
	}
	while (1) {
		int m = n - k;
		if (l > 100 || m<0) { //음수인 경우, 길이100 이상인 경우 제외
			b = false;
			break;
		}
		else if (m % l == 0) {
			ans = m / l;
			break;
		}
		else {
			k += l;
			l++;
		}
	}
	if (b) {
		for (int i = 0; i < l; i++) {
			cout << ans+i  << " ";
		}
	}
	else cout << "-1";
	return 0;
}
