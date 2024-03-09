#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[102];
int dp[102];

bool compare(pair<int, int>& a, pair<int, int>& b) {
	return a.first < b.first;
}

int main(void) {
	int n, a, b;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		arr[i] = v[i].second;
	}
	int max = 0;
	for (int i = 0; i < n; i++) { 
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (min < dp[j]) min = dp[j];
			}
		}
		dp[i] = min + 1;
		if (max < dp[i]) max = dp[i];
	}
	cout << n - max;
	return 0;
}
