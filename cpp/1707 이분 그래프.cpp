#include<iostream>
#include<vector>
using namespace std;

int c[20001];
bool ans;
vector<int> ve[20001];

void dfs(int x, int prior) {
	if (c[prior] == 1) c[x] = 2;
	else c[x] = 1;
	for (int i = 0; i < ve[x].size(); i++) {
		if (c[ve[x][i]] != 0) {
			if (c[ve[x][i]] == c[x]) {
				ans = true;
				return;
			}
		}
		else dfs(ve[x][i], x);
	}
}

int main(void) {
	int t;
	cin >> t;
	while (t != 0) {
		t--;
		int v, e;
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			ve[a].push_back(b);
			ve[b].push_back(a);
		}
		for (int i = 1; i <= v; i++) if (c[i] == 0) dfs(i, 0);
		if (ans) cout << "NO\n";
		else cout << "YES\n";
		for (int i = 1; i <= v; i++) {
			ve[i].clear();
			c[i] = 0;
		}
		ans = false;
	}
	return 0;
}
