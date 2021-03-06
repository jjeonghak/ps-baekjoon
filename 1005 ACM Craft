#include<iostream>
#include<vector>
#include<queue>
#define MAX 1001
using namespace std;

int t, n, k, w;
vector<int> v[MAX];
int inDegree[MAX], times[MAX], result[MAX];

void topologySort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			result[i] = times[i];
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
			result[y] = max(result[y],result[x] + times[y]);
			if (--inDegree[y] == 0) q.push(y);
		}
	}
	printf("%d\n", result[w]);
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t != 0) {
		t--;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> times[i];
		}
		for (int i = 1; i <= k; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			inDegree[b]++;
		}
		cin >> w;
		topologySort();
		for (int i = 1; i <= n; i++) {
			times[i] = 0;
			result[i] = 0;
			inDegree[i] = 0;
			v[i].clear();
		}
	}
	return 0;
}
