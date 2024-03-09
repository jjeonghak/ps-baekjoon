#include<iostream>
#include<vector>
using namespace std;

int n;
long long ans;
vector<int> v;

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int le = start;
	int ri = mid + 1;
	vector<int> temp;

	if (start == end) return;
	merge(start, mid);
	merge(mid + 1, end);
	while (1) {
		if (le > mid || ri > end) break;
		else if (v[le] <= v[ri]) temp.push_back(v[le++]);
		else {
			ans += (mid + 1 - le);
			temp.push_back(v[ri++]);
		}
	}
	while (le <= mid) temp.push_back(v[le++]);
	while (ri <= end) temp.push_back(v[ri++]);
	int j = 0;
	for (int i = start; i <= end; i++) {
		v[i] = temp[j];
		j++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	merge(0, n - 1);
	cout << ans;
	return 0;
}
