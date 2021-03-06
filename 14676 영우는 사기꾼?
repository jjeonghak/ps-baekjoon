#include<iostream>
#include<vector>
#define MAX 100001
using namespace std;

int n, m, k;
vector<int> v[MAX];
int sum[MAX], inDegree[MAX];


bool topologySort() {
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			if (inDegree[b] == 0) {
				sum[b]++;
				if (sum[b] == 1) {
					for (int j = 0; j < v[b].size(); j++) inDegree[v[b][j]]--;
				}
			}
			else return false;
		}
		else {
			if (sum[b] > 0) {
				sum[b]--;
				if (sum[b] == 0) {
					for (int j = 0; j < v[b].size(); j++) inDegree[v[b][j]]++;
				}
			}
			else return false;
		}
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		inDegree[b]++;
	}
	bool ans = topologySort();
	if (ans) printf("King-God-Emperor");
	else printf("Lier!");
	return 0;
}
