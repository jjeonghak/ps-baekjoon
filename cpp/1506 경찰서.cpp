#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 101
using namespace std;

int n;
int id, d[MAX];
bool finished[MAX];
vector<int> v[MAX];
vector<vector<int>> scc;
stack<int> s;
int cost[MAX];

int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int result = d[x];
	for (int i = 0; i <v[x].size(); i++) {
		int y = v[x][i];
		if (d[y] == 0) result = min(result, dfs(y));
		else if (!finished[y]) result = min(result, d[y]);
	}

	if (result == d[x]) {
		vector<int> subscc;
		while (!s.empty()) {
			int z = s.top();
			s.pop();
			subscc.push_back(z);
			finished[z] = true;
			if (z == x) break;
		}
		scc.push_back(subscc);
	}
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char a;
			cin >> a;
			if (a == '1') v[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) dfs(i);
	}
	int ans = 0;
	for (int i = 0; i < scc.size(); i++) {
		int temp = 1000001;
		for (int j = 0; j < scc[i].size(); j++) {
			if (temp > cost[scc[i][j]]) temp = cost[scc[i][j]];
		}
		ans += temp;
	}
	printf("%d", ans);
}
