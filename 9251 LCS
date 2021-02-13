#include<iostream>
using namespace std;

int lcs[1001][1001];

int main(void) {
	string a, b;
	cin >> a >> b;
	for (int i = 0; i <= a.length(); i++) { //첫째줄들은 0으로 초기화하기위해 문자열 +1 크기로
		for (int j = 0; j <= b.length(); j++) {
			if (i == 0 || j == 0) lcs[i][j] = 0;
			else if (a[i-1] == b[j-1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	cout << lcs[a.length()][b.length()];
	return 0;
}
