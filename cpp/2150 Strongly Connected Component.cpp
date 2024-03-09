#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 10001
using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> v[MAX];
vector<vector<int>> scc;
stack<int> s;

int dfs(int x) { //항상 처음 방문한 노드만 실행, 총 n번 실행 
	d[x] = ++id; //노드별 고유 번호
	s.push(x);

	int result = d[x];
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (d[y] == 0) result = min(result, dfs(y)); //아직 방문하지 않은 이웃 노드
		else if (!finished[y]) result = min(result, d[y]); //방문 했지만 아직 처리중인 이웃 노드
	}
	if (result == d[x]) { //부모 노드가 자기 자신인 경우 scc 형성
		vector<int> subscc;
		while (1) {
			int t = s.top();
			s.pop();
			subscc.push_back(t);
			finished[t] = true;
			if (t == x) break; //자기 자신이 나올 때까지 
		}
		sort(subscc.begin(), subscc.end());
		scc.push_back(subscc); //정렬후 삽입
	}
	return result; //부모값 리턴
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int v1, e;
	cin >> v1 >> e;
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	for (int i = 1; i <= v1; i++) {
		if (d[i] == 0) dfs(i);
	}
	printf("%d\n", scc.size());
	sort(scc.begin(), scc.end());
	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			printf("%d ", scc[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}
