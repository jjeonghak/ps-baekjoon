#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int a[100010];
stack<int>s;
vector<char>v;
int main(void) {
	vector<char>::iterator m;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int j = 1;
	int l = 0;
	s.push(1);
	v.push_back('+');
	while (1) {
		if (s.empty()) { //만약 s가 비어있다면 코드에 오류가 나서 따로 취급
			j++;
			if (j > n) break;
			s.push(j);
			v.push_back('+');
		}
		else if (a[l] == s.top()) {
			l++;
			s.pop();
			v.push_back('-');
		}
		else {
			j++;
			if (j > n) break;
			s.push(j);
			v.push_back('+');
		}
	}
	if (s.empty()) {
		for (m = v.begin(); m != v.end(); m++) {
			printf("%c\n", *m);
		}
	}
	else printf("NO");
	return 0;
}
