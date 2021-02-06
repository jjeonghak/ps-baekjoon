#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int n, b;
	vector<int> v;
	cin >> n >> b;
	while (n != 0) {
		v.push_back(n % b);
		n /= b;
	}
	int temp = v.size();
	for (int i = 0; i <temp ; i++) {
		if (v.back() < 10) cout << v.back();
		else cout << (char)(v.back() + 55);
		v.pop_back();
	}
	return 0;
}
