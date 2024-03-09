#include<iostream>
using namespace std;

int main(void) {
	string s;
	int arr[25] = { 0, };
	cin >> s;
	int sum = 0, temp = 0, j = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {
			sum += temp;
			arr[j] = sum;
			j++;
			temp = 0;
			sum = 0;
		}
		else if (s[i] == '+') {
			sum += temp;
			temp = 0;
		}
		else {
			temp *= 10;
			temp += s[i] - '0';
		}
	}
	sum += temp;
	arr[j] = sum;
	int ans = arr[0];
	for (int i = 1; i < 25; i++) {
		ans -= arr[i];
	}
	cout << ans;

	return 0;
}
