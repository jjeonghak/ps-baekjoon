#include<iostream> //C++
using namespace std;
int T;
int a[1000000], b[1000000], sum[1000000];

int main(void) {
	
	ios_base::sync_with_stdio(false); //실행속도가 빨라짐
	cin.tie(NULL); 
	cout.tie(NULL); //하지만 stdio함수와 동시 사용불가

	cin >> T;
		for (int i = 1; i <= T; i++) {
			cin >> a[i] >> b[i];
			sum[i] = a[i] + b[i];
			cout << sum[i] << "\n";
		}
	return 0;
}
