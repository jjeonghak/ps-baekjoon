#include<iostream>
using namespace std;

int arr[101];

int sol(int a, int b) {
	int temp = 1;
	int i = 2;
	while (1) {
		if (a == 1 && b == 1) break; 
		if (a % i == 0 && b % i == 0) {
			a /= i;
			b /= i;
			temp *= i;
		}
		else if (a % i == 0) a /= i;
		else if (b % i == 0) b /= i;
		else i++;
	}
	return temp;
}

int main(void){
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	m = arr[0];
	for (int i = 1; i < n; i++) {
		if (m % arr[i] == 0) cout << m / arr[i] << "/" << 1 << endl;
		else {
			int temp = sol(m, arr[i]);
			cout << m / temp << "/" << arr[i] / temp << endl;
		}
	}
	return 0;
}
