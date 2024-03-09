#include<iostream>
#include<algorithm>
using namespace std;
pair<int, string>p[100001];

bool compare(const pair<int,string>&p1,const pair<int,string>&p2) {
	return p1.first < p2.first;
}

int main(void) {
	int n;
	string s;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> s;
		p[i].second = s;
	}
	stable_sort(p, p + n,compare); //stable = 상태가 같으면 변하지 않음
	for (int i = 0; i < n; i++) {
		printf("%d %s\n", p[i].first,p[i].second.c_str()); //printf에서 string 클래스 출력하는 방법 = string 객체 뒤에 .c_str()
	}
	return 0;
}
