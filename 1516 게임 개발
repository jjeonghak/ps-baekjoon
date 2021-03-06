#include<iostream>
#include<vector>
#include<queue>
#define MAX 501
using namespace std;

int n, inDegree[MAX], time[MAX], result[MAX];
vector<int> v[MAX];

void topologySort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) { //진입차수가 0인 노드 큐에 삽입
		if (inDegree[i] == 0) {
			result[i] = time[i];
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
			result[y] = max(result[y], result[x] + time[y]); //이전의 최댓값과 비교하여 큰 값
			if (--inDegree[y] == 0) { //새롭게 진입차수가 0이된 정점
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\", result[i]);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i];
		while (1) {
			int a;
			cin >> a;
			if (a == -1) break;
			inDegree[i]++;
			v[a].push_back(i);
		}
	}
	topologySort();
	return 0;
}
