#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> v[1001];
queue<int> q;
int c1[1001];
int c2[1001];

void dfs(int x) {
	c1[x] = true; //노드 x를 방문
	cout << x <<" ";
	for (int i = 0; i < v[x].size(); i++) { //노드 x에 연결된 만큼
		if (!c1[v[x][i]]) dfs(v[x][i]); //방문하지 않았을 경우 재귀
	}
}

void bfs(int x) {
	q.push(x); //처음 노드 x
	c2[x] = true;
	while (!q.empty()) {
		int now = q.front(); //현재 노드
		q.pop(); //방문한 노드 제거
		cout << now << " ";
		for (int i = 0; i < v[now].size(); i++) { //현재 노드에 연결된 만큼
			if (!c2[v[now][i]]) { //방문하지 않았을 경우 큐에 삽입
				q.push(v[now][i]); 
				c2[v[now][i]] = true;
			}
		}
	}
}

int main(void) {
	int a, b, n, m;
	int s;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(s);
	cout << endl;
	bfs(s);
	return 0;
}
