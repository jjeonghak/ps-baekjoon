#include<iostream>
#define MAX 1000001
using namespace std;

int a[MAX];
int n;

void primeNumberSieve() { //소수만 남기고 0초기화
	for (int i = 2; i <= MAX; i++) {
		a[i] = i; //배열 초기화
	}
	for (int i = 2; i <= MAX; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j <= MAX; j += i) { //다음 배수부터 시작해서 모든 배수를 0초기화
			a[j] = 0;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	primeNumberSieve();
	int t = 100000;
	while (t--) {
		cin >> n;
		if (n == 0) break;
		for (int i = n - 3; i > 1; i--) {
			if (a[i] != 0) {
				if (n == a[i] + a[n - i]) {
					printf("%d = %d + %d\n", n, a[n - i], a[i]);
					break;
				}
			}
		}
	}
	return 0;
}
