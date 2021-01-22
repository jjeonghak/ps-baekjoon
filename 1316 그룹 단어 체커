#include<iostream>
using namespace std;

string a;
int al[26];

int check(string arr) {
	for (int i = 0; i < arr.length(); i++) {
		if (i == arr.length() - 1) {
			if (al[arr[i] - 97] == 1) return 0;
		}
		else if (arr[i] != arr[i + 1]) {
			al[arr[i]-97]++;
			if (al[arr[i] - 97] != 1) return 0;
		}
	}
	return 1;
}

int main(void) {
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum += check(a);
		for (int i = 0; i < 26; i++) { //사용한 배열 초기화
			al[i] = 0;
		}
	}
	cout << sum;
	return 0;
}
