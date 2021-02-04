#include<iostream>
using namespace std;

long long a, b, c;

long long sol(long long x, long long n) {
	if (n == 0) return 1;
	else if (n == 1) return x % c;
	if (n % 2 !=0) return x * sol(x, n - 1) % c;
	long long d = sol(x, n / 2) % c;
	return (d * d) % c;
}

int main(void) {
	cin >> a >> b >> c;
	cout<<sol(a, b);
	return 0;
}
