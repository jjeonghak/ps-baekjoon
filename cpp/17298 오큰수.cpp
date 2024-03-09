#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int n, a;
	vector<int>v1, v2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v1.push_back(a);
	}
	vector<int>ans(v1.size(), -1); //v1의 사이즈로 -1
	for (int i = 0; i < v1.size(); i++) {
		while (!v2.empty() && v1[v2.back()] < v1[i]) {
			ans[v2.back()] = v1[i];
			v2.pop_back();
		}
		v2.push_back(i);
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}
