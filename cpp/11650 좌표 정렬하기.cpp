#include<iostream>
#include<algorithm>
using namespace std;
pair<int, int>p[100001];

bool compare(pair<int,int>p1,pair<int,int>p2) { //pair 정렬하는 방법
	if (p1.first == p2.first) return p1.second <= p2.second;
	return p1.first <= p2.first;
}

int main(void) {
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n, compare);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", p[i].first, p[i].second); //시간 초과 방지를 위한 printf
	}
	return 0;
}
