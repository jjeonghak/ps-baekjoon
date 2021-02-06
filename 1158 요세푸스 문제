#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int n, k;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		 v.push_back(i);
	}
	int cnt = k-1;
	int m = n;
	printf("<");
	for (int i = 0; i < n; i++) {
		printf("%d", v[cnt]);
		if(i==n-1) printf(">");
		else printf(", ");
		v.erase(v.begin() + cnt);
		cnt += (k - 1); //한명이 사라짐과 동시에 현재 포인터는 사라진 다음 수를 가리키므로 -1
		if (--m > 0) cnt %= m; //현재 남아있는 사람으로 나눈 나머지가 다음 위치
	}
	return 0;
}
