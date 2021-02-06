#include<iostream>
using namespace std;

int map[10][10];
bool cr[10][10];
bool cc[10][10];
bool cb[10][10];

int box(int x, int y) { //(x,y)가 포함된 정사각형(0~8)
	return (x / 3) * 3 + (y / 3);
}

void sol(int a) {
	if (a == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0); //return은 해당함수만, exit(0)는 프로그램 종료
	}
	int x = a / 9; //몇번째 줄인지
	int y = a % 9; //몇번째 자리인지
	if (map[x][y] != 0) sol(a + 1); //0이면
	else {
		for (int i = 1; i <= 9; i++) { //들어갈 숫자 찾기
			if (cr[x][i] == 0 && cc[y][i] == 0 && cb[box(x, y)][i] == 0) {
				cr[x][i] = cc[y][i] = cb[box(x, y)][i] = true;
				map[x][y] = i;
				sol(a + 1); //(x,y)에 i번 숫자가 아니면 백트래킹(a=81이 안되고 재귀종료), 맞으면 기저조건으로 인한 종료
				map[x][y] = 0; //즉, 앞에 i가 틀렸을 경우만 다시 백트래킹
				cr[x][i] = cc[y][i] = cb[box(x, y)][i] = false;
			}
		}
	}
	
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				cr[i][map[i][j]] = cc[j][map[i][j]] = cb[box(i, j)][map[i][j]] = true; //각 열, 행, 박스에 이미 입력된 숫자 저장
			}
		}
	}
	sol(0);
	return 0;
}
