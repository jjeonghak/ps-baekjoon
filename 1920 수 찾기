#include<iostream>
#include<algorithm>
using namespace std;
int a[100000];
int sol(int le, int ri,int val) {
	int mid = (le + ri) / 2;
	if (le > ri) return 0; //값이 없음, 범위가 좁아지지만 le 혹은 ri는 고정되어 있음
	if (val > a[mid]) return sol(mid + 1, ri, val);
	else if (val < a[mid]) return sol(le, mid - 1, val);
	else return 1; //값이 존재
}

int main(void) {
	int n, m, val;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1); //오름차순 정렬
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> val;
		printf("%d\n", sol(1, n, val));
	}
	return 0;
}
