#include <stdio.h>
#include <algorithm>
using namespace std;

int upperBound(int);
int lowerBound(int);

int arr[5000001];
int n, m, s, mid, e;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int k, ans;
		scanf("%d", &k);
		int upidx = upperBound(k);
		int loidx = lowerBound(k);

		if (arr[loidx] == k) {
			ans = upidx - loidx + 1;
		}
		else {
			ans = 0;
		}
		printf("%d ", ans);
	}
	return 0;
}

int upperBound(int a) {

	s = 0; e = n - 1;

	while (e - s > 0) {
		mid = (s + e) / 2;

		if (arr[mid] <= a) { s = mid + 1; } // 타겟값이 처음 나오는 
		else e = mid;
	}

	if (arr[e] != a) { e -= 1; }

	return e;
}

int lowerBound(int a) {

	s = 0; e = n - 1;

	while (e - s > 0) {
		mid = (s + e) / 2;

		if (arr[mid] < a) { s = mid + 1; } // 타겟값을 초과하는 값이 처음 나온 곳
		else e = mid;
	}

	return e;
}
