#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int cnt = 0;
	int a = 665;
	string s;
	while (++a) {
		s = to_string(a);
		if (s.find("666")!=-1) {
			cnt++;
		}
		if (cnt == n) {
			cout << a;
			break;
		}
	}
	return 0;
}
