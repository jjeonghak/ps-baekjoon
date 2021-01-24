#include<iostream>
using namespace std;

int number = 10000;
int a[10001];

void primeNumberSieve() { //소수만 남기고 0초기화
	for (int i = 2; i <= number; i++) {
		a[i] = i; //배열 초기화
	}
	for (int i = 2; i <= number; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j <= number; j += i) { //다음 배수부터 시작해서 모든 배수를 0초기화
			a[j] = 0;
		}
	}
}

int main(void) {
	int n,t;
	primeNumberSieve();
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int m = n / 2;
		for (int j = 1; j <= m; j++) {
			if (a[m] != 0) {
				cout << m << " " << m << endl;
				break;
			}
			else if (a[m + j] != 0 && a[m - j] != 0) {
				cout << m - j << " " << m + j << endl;
				break;
			}
		}
	}
	return 0;
}
