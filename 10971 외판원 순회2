#include<iostream>
#include<algorithm>
using namespace std;

int n;
int map[11][11];
int temp = 2147483640;
bool cc[11];

void dfs(int sum,int start,int end,int cnt) {
	if (!cc[end]) { //맨처음 시작도시는 아직 false 상태
		for (int j = 1; j <= n; j++) {
			if (map[end][j] != 0) {
				cc[end] = true; //맨마지막에 시작도시 true한 경우 1), 아닌 경우 2)
				sum += map[end][j];
				cnt++;
				dfs(sum, start, j, cnt);
				cc[end] = false;
				sum -= map[end][j];
				cnt--;
			}
		}
	}
	if (cnt == n && start == end) { // 1)시작도시가 true이고 마지막이므로 탐색종료
		temp = min(temp, sum);
		return;
	}
	return; // 2)시작도시를 마지막으로 하지않고 탐색이 끝난 경우, return 없어도 상관없음
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		dfs(0, i, i, 0);
	}
	cout << temp;
	return 0;
}
