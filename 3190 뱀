#include<iostream>
#include<queue>

int n, k, l;
int map[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::queue<std::pair<int, char>> q;
	std::queue<std::pair<int, int>> q1;
	std::pair<int, int>  head = { 1, 1 }, tail = { 1, 1 };

	std::cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		std::cin >> a >> b;
		map[a][b] = 1;
	}
	std::cin >> l;
	for (int i = 0; i < l; i++) {
		int a;
		char b;
		std::cin >> a >> b;
		q.push({ a, b });
	}
	int time = 0, direction = 0;
	map[1][1] = 3;

	while (1) {
		if (!q.empty() && q.front().first == time) {
			if (q.front().second == 'D') direction = (direction + 1) % 4;
			else if (direction == 0) direction = 3;
			else direction--;
			q.pop();
		}
		std::pair<int, int> nh = { head.first + dy[direction], head.second + dx[direction] };
		q1.push({ dy[direction], dx[direction] });
		if (nh.first > n || nh.first < 1 || nh.second > n || nh.second < 1
			|| map[nh.first][nh.second] == 3) break;
		else if (map[nh.first][nh.second] == 0) {
			map[tail.first][tail.second] = 0;
			tail = { tail.first + q1.front().first, tail.second + q1.front().second };
			q1.pop();
		}
		map[nh.first][nh.second] = 3;
		head = nh;
		time++;

	}
	std::cout << time + 1;
	return 0;
}
