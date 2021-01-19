#include<iostream>
using namespace std;

int main(void) {
	long long x, y;
	int z;

	cin >> x >> y;
	z = 100 * y / x;
	if (z >= 99) { // z=99는 더이상 올라갈수 없다
		cout << "-1";
	}
	else {
		int le = 0;
		int ri = 1000000000;
		int mid, k;
		while (le <= ri) {
			mid = (le + ri) / 2;
			k = 100 * (y + mid) / (x + mid);
			if (z < k) ri = mid - 1;
			else le = mid + 1;
		}
		cout << le;
	}
	return 0;
}
