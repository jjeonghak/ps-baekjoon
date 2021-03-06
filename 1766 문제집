#include<iostream>
#include<vector>
#include<queue>
#define MAX 32001
using namespace std;

int n, m;
vector<int> v[MAX];
int inDegree[MAX];

void topologySort() {
	priority_queue<int> pq;
	queue<int> ans;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) pq.push(-i);
	}
	for (int i = 1; i <= n; i++) {
		int x = -pq.top();
		ans.push(x);
		pq.pop();
		for (int j = 0; j < v[x].size(); j++) {
			if (--inDegree[v[x][j]] == 0) pq.push(-v[x][j]);
		}
	}
	while (!ans.empty()) {
		printf("%d ", ans.front());
		ans.pop();
	}
}

int main(void) {
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
