#include<iostream>
using namespace std;
int a[1001];
int dp[1001];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = 0;
	for (int i = 0; i < n; i++) { //자기 자신보다 작은 항 탐색
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (a[i]>a[j]) { 
				if (min < dp[j]) min = dp[j];
			}
		}
		dp[i] = min + 1; 
		if (max < dp[i]) max = dp[i]; 
	}
	cout << max;
	return 0;
}
