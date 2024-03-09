#include<iostream>
using namespace std;

int n, s, ans;
int a[21];

void bt(int cnt, int sum) {
	if (cnt == n) return; //n개를 다 더한 경우
	if (sum + a[cnt] == s) ans++; //합이 s인 경우 ans 하나 증가후 계속 이어서 탐색
	bt(cnt + 1, sum); //현재 cnt 값을 안 더한 경우
	bt(cnt + 1, sum + a[cnt]); //현재 cnt 값을 더한 경우
}

int main(void) {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bt(0,0);
	cout << ans;
	return 0;
}
