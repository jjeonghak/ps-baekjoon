#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 100001
using namespace std;

int n, m;
int id, d[MAX];
bool finished[MAX];
vector<int> v[MAX];
vector<vector<int>> scc;
stack<int> s;
int group[MAX];
bool inDegree[MAX];
vector<int> res;

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
			group[t] = scc.size() + 1; //그룹번호는 이때까지 쌓여잇는 scc의 갯수 + 1
			finished[t] = true;
			if (t == x) break; //자기 자신이 나올 때까지 
		}
		scc.push_back(subscc); //정렬후 삽입
	}
	return result; //부모값 리턴
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		scc.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, 0);
		fill(inDegree, inDegree + MAX, false);
		res.clear();
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			v[x + 1].push_back(y + 1);
		}
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) dfs(i);
		}
		for (int i = 1; i <= n; i++) { //간선 처리
			for (int j = 0; j < v[i].size(); j++) {
				int z = v[i][j];
				if (group[i] != group[z]) inDegree[group[z]] = true; //scc로 연결되어 있는 경우
			}
		}
		int cnt = 0;
		for (int i = 0; i < scc.size(); i++) {
			if (!inDegree[i + 1]) {
				cnt++;
				for (int j = 0; j < scc[i].size(); j++) {
					res.push_back(scc[i][j] - 1);
				}
			}
		}
		sort(res.begin(), res.end());
		if (cnt != 1) {
			printf("Confused\n\n");
		}
		else {
			for (int i = 0; i < res.size(); i++) {
				printf("%d\n", res[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
