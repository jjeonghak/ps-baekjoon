#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector <long long> v;

void decline(long long a, int cnt) { 
	if (cnt > 10) return; //최대 감소하는 수의 자리수 10
	else {
		v.push_back(a); 
		for (int i = 0; i < 10; i++) { 
			if (a % 10 > i) decline(a * 10 + i, cnt + 1);  //앞자리가 크다면
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < 10; i++) {
		decline(i, 1); //앞자리 수가 i인 모든 감소하는 수
	}
	sort(v.begin(), v.end()); //모든 감소하는 수 정렬
	long long res;
	if (v.size() <= n) res = -1; 
	else res = v[n];
	cout << res;
	return 0;
}
