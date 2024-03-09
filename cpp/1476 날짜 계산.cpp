#include<iostream>
using namespace std;

int main(void) {
	int e, s, m;
	cin >> e >> s >> m;
	int ans = 1;
	while (1) {
		if ((ans - e) % 15 == 0 && (ans - s) % 28 == 0 && (ans - m) % 19 == 0) {
			cout << ans;
			break;
		}
		else ans++;
	}
	return 0;
}
