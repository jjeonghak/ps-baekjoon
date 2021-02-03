#include<iostream>
using namespace std;

int a[100][100];
int b[100][100];
int c[100][100];

int main(void) {
	int n,m,n1;
	cin >> n1 >> m;
	for (int j = 0; j < n1; j++) {
		for (int k = 0; k < m; k++) {
			cin >> a[j][k];
		}
	}
	cin >> n >> m;
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < m; k++) {
			cin >> b[j][k];
		}
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
