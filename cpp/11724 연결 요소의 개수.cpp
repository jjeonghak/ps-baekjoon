#include<iostream>
#include<vector>
using namespace std;
vector<int>node[10002];
int c[10002];

void dfs(int x) {
	c[x] = true; 
	for (int i = 0; i < node[x].size(); i++) { 
		if (!c[node[x][i]]) dfs(node[x][i]); 
	}
}

int main(void) {
	int n, m, u, v;
	int res = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) {
			dfs(i);
			res++;
		}
	}
	cout << res;
	return 0;
}
