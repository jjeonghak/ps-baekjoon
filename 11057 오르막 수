#include<iostream>
#include<vector>
using namespace std;

long long sum[100010];

long long sol(int x) {
	if (sum[x] != 0) return sum[x];
	else {
		for (int i = 1+(x%10); i <= 10; i++) {
			sum[x] += sol(x - i)%10007;
		}
		return sum[x];
	}
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		sum[i] = 1;
	}
	sol(10 * n);
	cout << sum[10*n]%10007;
	return 0;
}
