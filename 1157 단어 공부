#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char a;
vector<int>v[26];

int main(void) {
	int i = 0;
	while (1) {
		a = cin.get();
		if (a >= 65 && a <= 90) {
			v[(int)a - 65].push_back(1);
		}
		else if (a >= 97 && a <= 122) {
			v[(int)a - 97].push_back(1);
		}
		else break;
	}
	int m = 0;
	int al;
	int b[26];
	for (int i = 0; i < 26; i++) {
		b[i] = v[i].size();
		if (m < b[i]) {
			m = b[i]; 
			al = i; //최댓값의 알파벳 위치 저장
		}
	}
	sort(b, b + 26); 
	if (b[25] != b[24]) { //정렬 후 최댓값가 차선값이 동일한 값인지 확인
		cout << char(al + 65);
	}
	else cout << "?";
	return 0;
}
