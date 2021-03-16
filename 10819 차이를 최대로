#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int n;
	int a[10];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int temp, ans = 0;
	while (next_permutation(a,a+n)) {//배열의 순서를 바꾸고, true값 반환
		temp = 0;
		for (int i = 0; i < n - 1; i++) {
			temp += abs(a[i] - a[i + 1]);
		}
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}
