#include<iostream>
#include<vector>
using namespace std;

int map[65][65];
vector<char> v;

void sol(int a, int b, int c) { //시작점과 변크기
	for (int i = a; i < a + c / 2; i++) {
		bool check = false;
		for (int j = b; j < b + c / 2; j++) {
			if (map[a][b] != map[i][j]) {
				v.push_back('(');
				sol(a, b, c / 2);
				v.push_back(')');
				check = true;
				break;
			}
			else if (i == a + c / 2 - 1 && j == b + c / 2 - 1) v.push_back(map[a][b]+'0');
		}
		if (check) break;
	}
	for (int i = a; i < a + c / 2; i++) {
		bool check = false;
		for (int j = b + c / 2; j < b + c; j++) {
			if (map[a][b + c / 2] != map[i][j]) {
				v.push_back('(');
				sol(a, b + c / 2, c / 2);
				v.push_back(')');
				check = true;
				break;
			}
			else if (i == a + c / 2 - 1 && j == b + c - 1) v.push_back(map[a][b+c/2] + '0');
		}
		if (check) break;
	}
	for (int i = a + c / 2; i < a + c; i++) {
		bool check = false;
		for (int j = b; j < b + c / 2; j++) {
			if (map[a + c / 2][b] != map[i][j]) {
				v.push_back('(');
				sol(a + c / 2, b, c / 2);
				v.push_back(')');
				check = true;
				break;
			}
			else if (i == a + c - 1 && j == b + c / 2 - 1) v.push_back(map[a+c/2][b] + '0');
		}
		if (check) break;
	}
	for (int i = a + c / 2; i < a + c; i++) {
		bool check = false;
		for (int j = b + c / 2; j < b + c; j++) {
			if (map[a + c / 2][b + c / 2] != map[i][j]) {
				v.push_back('(');
				sol(a + c / 2, b + c / 2, c / 2);
				v.push_back(')');
				check = true;
				break;
			}
			else if (i == a + c - 1 && j == b + c - 1) v.push_back(map[a + c / 2][b+c/2] + '0');
		}
		if (check) break;
	}
}

int main(void) {
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char m;
			cin >> m;
			map[i][j] = m - '0';
		}
	}	
	sol(0, 0, n);
	if (v.size() == 4 && v[0] == v[1] && v[1] == v[2] && v[2] == v[3]) printf("%c", v[0]);
	else {
		printf("(");
		for (int i = 0; i < v.size(); i++) printf("%c", v[i]);
		printf(")");
	}
	return 0;
}
