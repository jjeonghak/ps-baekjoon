#include<iostream>
#include<algorithm>
using namespace std;

int a[10003];
int dp[10003];

int main(void) {
	int n;
	cin >> n;
	for (int i = 3; i < n+3; i++) { //3가지 이전 항과의 비교를 위헤
		cin >> a[i];
	}
	for (int i = 3; i < n + 3; i++) {
		int temp = max(dp[i - 3] + a[i - 1] + a[i], dp[i - 2] + a[i]); //두가지 연달아 마시는 경우
		dp[i] = dp[i - 1] < temp ? temp : dp[i - 1]; //건너뛰며 마시는 
	}
	cout << dp[n + 2];
	return 0;
}
