#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int n;
	vector<int>v;
	vector<int>::iterator k;
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin >> n;
	int temp = n;
	int j = 2;
	while (1) {
		if (temp % j == 0) {
			temp /= j;
			v.push_back(j);
		}
		else j++;
		if (temp == 1)break;
	}
	for (k = v.begin(); k != v.end(); k++) {
		cout << *k << endl;
	}
	return 0;
}
