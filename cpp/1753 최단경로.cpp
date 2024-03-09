#include<iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321

int dis[20010];
vector<pair<int, int>> graph[20010];

priority_queue<pair<int, int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int v, e, k;
	cin >> v >> e >> k;

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}
	for (int i = 1; i <= v; i++) dis[i] = INF;

	dis[k] = 0;
	pq.push({ 0,k });

	while (!pq.empty()) {
		int now = pq.top().second;
		int nowdis = -pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			pair<int, int> next = graph[now][i];
			if (dis[next.first] >= nowdis + next.second) {
				dis[next.first] = nowdis + next.second;
				pq.push({ -dis[next.first],next.first });
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dis[i] == INF) printf("INF\n");
		else printf("%d\n", dis[i]);
	}
	return 0;
}
