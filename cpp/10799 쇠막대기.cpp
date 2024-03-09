#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	string a;
	int ans = 0;
	vector<char> v;
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '(') v.push_back(a[i]);
		else if(a[i]==')'&&a[i-1]==')'){
			v.pop_back();
			ans ++;
		}
		else {
			v.pop_back();
			ans += v.size();
		}
	}
	cout << ans;
	return 0;
}
