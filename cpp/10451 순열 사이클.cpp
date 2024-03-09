#include<iostream>
using namespace std;

int arr[1001];
bool c[1001];
int ans;

void dfs(int x) {
	if (c[x]) {
		ans++;
		return;
	}
	c[x] = true;
	dfs(arr[x]);
}

int main(void) {
	int t;
	cin >> t;
	while (t != 0) {
		t--;
		int n;
		cin >> n;
		for (int i = 1; i <=n; i++) {
			int a;
			cin >> a;
			arr[i] = a;
		}
		for (int i = 1; i <= n; i++) if (!c[i]) dfs(i);
		cout << ans << "\n";
		ans = 0;
		for (int i = 1; i <= n; i++) {
			c[i] = false;
		}
	}
	return 0;
}
