#include<iostream>
#include<algorithm>
#define MAX 1001
using namespace std;

int we[MAX];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> we[i];
	}
	sort(we, we + n);
	if (we[0] != 1) printf("1");
	else {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (we[i] > sum + 1) break;
			else sum += we[i];
		}
		printf("%d", sum + 1);
	}
	return 0;
}
