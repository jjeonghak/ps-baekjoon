#include<iostream>
using namespace std;

int lcs[1001][1001];
char ans[1001];

int main(void) {
	string a, b;
	int k = 0;
	cin >> a >> b;
	for (int i = 0; i <= a.length(); i++) {
		for (int j = 0; j <= b.length(); j++) {
			if (i == 0 || j == 0) lcs[i][j] = 0;
			else if (a[i - 1] == b[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;\
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	cout << lcs[a.length()][b.length()] << "\n";
	int i = a.length(), j = b.length();
	while (lcs[i][j] != 0) {
		if (lcs[i][j] == lcs[i - 1][j]) i -= 1;
		else if (lcs[i][j] == lcs[i][j - 1]) j -= 1;
		else {
			ans[k] = a[i-1]; //넣을 때도 하나 차이 
			i -= 1;
			j -= 1;
			k++;
		}
	}
	for (int i = k-1; i >=0; i--) {
		cout << ans[i];
	}
	return 0;
}
