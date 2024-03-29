#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string, int>m; //map을 사용, 정렬은 새로운 벡터로

bool compare(const pair<string,int>& a,const pair<string,int>& b) {
	return a.first > b.first;
}

int main(void) {
	int n;
	string a, b;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (b == "enter") {
			m[a] = 1;
		}
		else m[a] = 0;
	}
	vector<pair<string,int>> vec(m.begin(), m.end()); //map을 새로운 벡터로 선언
	sort(vec.begin(), vec.end(), compare); //새로운 벡터 정렬
	vector<pair<string, int>>::iterator j;

	for (j = vec.begin(); j != vec.end(); j++) {
		if (j->second != 0) cout << j->first << "\n"; //포인터 형식으로, printf로 실행 
	}
	return 0;
}
