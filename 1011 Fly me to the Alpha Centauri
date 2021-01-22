#include<iostream>
using namespace std;

int main(void) {
	long long x, y;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		long long sum=0;
		int cnt = 0;
		long long diff = y - x ;
		int j = 1;
		while (1) {
			for (int i = 0; i < 2; i++) {
				sum += j;
				cnt++;
				if (sum >= diff) break;
			}
			if (sum >= diff) break;
			j++;
		}
		cout << cnt << endl;
	}
	return 0;
}
