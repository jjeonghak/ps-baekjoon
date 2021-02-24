#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define MAX 101
using namespace std;

string a, b, c;
int arr[MAX][MAX][MAX];

// 7가지 경우의 수
// 1. a만 인덱스 증가
// 2. b만 인덱스 증가
// 3. c만 인덱스 증가
// 4. a와 b 인덱스 증가
// 5. a와 c 인덱스 증가
// 6. b와 c 인덱스 증가
// 7. a, b, c 모두 인덱스 증가

int lcs(int x, int y, int z) {
	if (x == a.length() || y == b.length() || z == c.length()) return 0; //기져사례, 문자열 범위이탈
	int& res = arr[x][y][z];
	if (res != -1) return res;
	res = max(lcs(x + 1, y, z), max(lcs(x, y + 1, z),lcs(x, y, z + 1))); //1,2,3인 경우
	res = max(max(res,lcs(x + 1, y+1, z)), max(lcs(x+1, y, z+1), lcs(x, y+1, z + 1))); //4,5,6인 경우
	res = max(res, (a[x] == b[y] && a[x] == c[z] && b[y] == c[z]) + lcs(x + 1, y + 1, z + 1)); //7인 경우
	return res;
}

int main(void) {
	cin >> a >> b >> c;
	memset(arr, -1, sizeof(arr));
	cout << lcs(0, 0, 0);
	return 0;
}
