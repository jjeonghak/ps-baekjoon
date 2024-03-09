#include<iostream>
using namespace std;

int arr[102][102][102];
int w(int a, int b, int c) { //음수 처리를 위해 모든 조건 +50
	if (a <= 50 || b <= 50 || c <= 50) return arr[a][b][c] = 1;
	else if (arr[a][b][c] != 0) return arr[a][b][c];
	else if (a > 70 || b > 70 || c > 70) return w(70, 70, 70);
	else if (a < b && b < c) return arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(void) {
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		a += 50; //음수처리를 위해
		b += 50;
		c += 50;
		int temp = w(a, b, c);
		cout << "w(" << a-50 << ", " << b-50 << ", " << c-50 << ") = " << temp << endl;
	}
	return 0;
}
