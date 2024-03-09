#include<iostream>
using namespace std;

int main(void) {
	int a, b;
	int ans1 = 1, ans2 = 1;
	int n;
	cin >> a >> b;
	int i = 2;
	while (1) {
		int a1 = 0;
		int b1 = 0;
		if (a == 1 && b == 1) break;
		if (a % i == 0) {
			a = a / i;
			a1++;
		}
		if (b % i == 0) {
			b = b / i;
			b1++;
		}
		if (a1 == 1 && b1 == 1) ans1 *= i;
		else if (a1 == 1 || b1 == 1) ans2 *= i;
		else i++;
	}
	cout << ans1 << endl << ans2 * ans1;
	return 0;
}
