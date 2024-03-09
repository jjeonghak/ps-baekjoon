#include<iostream>
#include<vector>
#include<queue>
#define MAX 1001
using namespace std;

int n, m;
int inDegree[MAX];
bool visit;
vector<int> v[MAX];

void topologySort() {
	queue<int> q;
	queue<int> ans;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {  //사이클 발생시 큐가 먼저 비어버림
			visit = true;
			return;
		}
		int x = q.front();
		ans.push(x);
		q.pop();
		for (int j = 0; j < v[x].size(); j++) {
			if (--inDegree[v[x][j]] == 0) q.push(v[x][j]);
		}
	}
	while (!ans.empty()) {
		printf("%d\n", ans.front());
		ans.pop();
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;
		queue<int> q1;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int c;
			cin >> c;
			q1.push(c);
		}
		while (1) {
			int x = q1.front();
			q1.pop();
			if (q1.empty()) break;
			else {
				v[x].push_back(q1.front());
				inDegree[q1.front()]++;
			}
		}
	}
	topologySort();
	if (visit) printf("0");
	return 0;
}
