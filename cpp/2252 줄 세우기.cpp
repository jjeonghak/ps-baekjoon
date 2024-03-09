#include<iostream>
#include<vector>
#include<queue>
#define MAX 32001
using namespace std;

int n, m, inDegree[MAX], result[MAX];
vector<int> v[MAX];

void topologySort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) { //진입차수가 0인 노드 큐에 삽입
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
			if (--inDegree[y] == 0) { //새롭게 진입차수가 0이된 정점
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
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
