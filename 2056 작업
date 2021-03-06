#include<iostream>
#include<vector>
#include<queue>
#define MAX 10001
using namespace std;

int n, ans = 0;
vector<int> v[MAX];
int times[MAX], result[MAX], inDegree[MAX];

void topologySort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			result[i] = times[i];
			ans = max(ans, result[i]);  //모든 작업의 선행이 없는 경우 대비
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
			result[y] = max(result[y], result[x] + times[y]);
			ans = max(ans, result[y]);
			if (--inDegree[y] == 0) q.push(y);
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		times[i] = a;
		for (int j = 0; j < b; j++) {
			int c;
			cin >> c;
			v[c].push_back(i);
			inDegree[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (result[i] == 0) topologySort();  //그래프가 두개인 경우 대비
	}
	printf("%d", ans);
	return 0;
}
