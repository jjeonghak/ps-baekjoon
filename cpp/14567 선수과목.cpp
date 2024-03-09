#include<iostream>
#include<vector>
#include<queue>
#define MAX 1001
using namespace std;

int n;
vector<int> v[MAX];
int inDegree[MAX];
int result[MAX];

void topologySort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			result[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
			result[y] = max(result[y], result[x] + 1);
			if (--inDegree[y] == 0) q.push(y);
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		inDegree[b]++;
	}
	topologySort();
	return 0;
}
