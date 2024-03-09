#include<iostream>
using namespace std;

int main(void) {
	int n;
	int ans=1;
	int sum;
	cin >> n;
	while (1) {
		sum = ans + ans % 10 + (ans / 10) % 10 + ((ans / 10) / 10) % 10 + (((ans / 10) / 10) / 10) % 10 + ((((ans / 10) / 10) / 10) / 10) % 10 + (((((ans / 10) / 10) / 10) / 10) / 10) % 10;
		if (ans == n) {
			ans = 0;
			break;
		}
        else if (sum == n) break;
		ans++;
	}
	cout << ans;
	return 0;
}
