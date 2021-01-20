#include<iostream>
#include<algorithm>
using namespace std;

string a[20000];
int n;

bool compare(string a, string b) { //길이가 짧은 순서
	if (a.length() < b.length()) return 1; //짧은 것이 우선
	else if (a.length() > b.length()) return 0;
	else return a < b; //string은 자동으로 사전순 비교
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n, compare); //string 배열이어도 다른 배열과 똑같이 선언
	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] == a[i - 1]) continue;
		else cout << a[i] << endl;
	}
	return 0;
}
