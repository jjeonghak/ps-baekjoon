#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int map[26][26];
int c[26][26];
int cnt, ans;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<int> v;

void dfs(int x, int y) {
	c[x][y] = cnt;
	ans++;
	for (int i = 0; i < 4; i++) {
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (c[newx][newy] == 0 && map[newx][newy] == 1) {
			if(newx > 0 && newx <= n && newy > 0 && newy <= n) dfs(newx, newy);
		}
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char a;
			cin >> a;
			map[i][j] = a - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (c[i][j] == 0 && map[i][j] == 1) {
				cnt++;
				dfs(i,j);
				v.push_back(ans);
				ans = 0;
			}
		}
	}
	cout << cnt << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}
