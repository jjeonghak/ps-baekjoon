#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
#define MAX 5001
using namespace std;

int n, m;
int id, d[MAX];
bool finished[MAX];
vector<int> v[MAX];
vector<vector<int>> scc;
vector<int> s;

int dfs(int x) {
	d[x] = ++id;
	s.push_back(x);

	int result = d[x];
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (d[y] == 0) result = min(result, dfs(y));
		else if (!finished[y]) result = min(result, d[y]);
		else result = 0;
	}
	if (result == d[x]) {
		vector<int> subscc;
		while (!s.empty()) {
			int t = s.back();
			s.pop_back();
			subscc.push_back(t);
			finished[t] = true;
			if (t == x) {
				s.clear();
				break;
			}
		}
		sort(subscc.begin(), subscc.end());
		scc.push_back(subscc);
	}
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		scc.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, 0);
		cin >> n;
		if (n == 0) break;
		cin >> m;
		if (m == 0) {
			string a;
			getline(cin, a);
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
		}
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) dfs(i);
		}
		vector<int> ans;
		for (int i = 0; i < scc.size(); i++) {
			for (int j = 0; j < scc[i].size(); j++) {
				ans.push_back(scc[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				v[i].clear();
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
