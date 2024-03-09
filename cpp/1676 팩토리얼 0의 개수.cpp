#include<iostream>
using namespace std;

int main(void) {
	int n;
	int cnt2 = 0, cnt5 = 0;
	cin >> n;
	int j = 1;
	int temp = 1;
	while(j!=n+1) {
		if (temp % 2 == 0) {
			temp /= 2;
			cnt2++;
		}
		else if (temp % 5 == 0) {
			temp /= 5;
			cnt5++;
		}
		else {
			j++;
			temp = j;
		}
	}
	if (cnt2 >= cnt5) cout << cnt5;
	else cout << cnt2;
	return 0;
}
