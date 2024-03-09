#include<iostream>
#include<vector>
using namespace std;
int n, m;
vector<int> v[101];
int c[101];
int res;

void dfs(int x) {
	if (c[x]) return;
	c[x] = true;
	res++;
	for (int i = 0; i < v[x].size(); i++) {
		dfs(v[x][i]);
	}
}

int main(void) {
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << res-1; //1번 컴퓨터는 포함안함
	return 0;
}
