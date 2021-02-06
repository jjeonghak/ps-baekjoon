#include<iostream>
using namespace std;

long long sol(long long a, long long b) {
	if (a % b == 0) return b;
	else return sol(b, a % b); //나눈 값과 나눈 나머지로 
}

int main(void) {
	long long a, b;
	cin >> a >> b;
	long long c = sol(a, b);
	for (int i = 0; i < c; i++) {
		printf("1");
	}
	return 0;
}
