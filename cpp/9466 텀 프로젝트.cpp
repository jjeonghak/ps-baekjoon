#include<iostream>
#include<cstring> //memset
using namespace std;

int n, cnt;
int a[100001];
bool c[100001];
bool finish[100001];

void dfs(int x) {
	c[x] = true;
	if (!c[a[x]]) dfs(a[x]);
	else if (!finish[a[x]]) { //방문했지만 끝난 노드가 아니라면 사이클
		for (int i = a[x]; i != x; i = a[i]) cnt++; //팀원
		cnt++; //자기자신
	}
	finish[x] = true; //더이상 방문 안함
}

int main(void) {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(c, false, sizeof(c));
		memset(finish, false, sizeof(finish));
		cin >> n;
		for (int j = 1; j <= n; j++) cin >> a[j];
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!finish[j]) dfs(j);
		}
		cout << n - cnt << "\n";
	}
	return 0;
}
