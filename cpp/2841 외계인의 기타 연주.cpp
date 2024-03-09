#include<iostream>
#include<stack>
using namespace std;

int N, P;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> P;

	stack <int> s[7]; //라인 1~6
	int sum = 0;

	for (int i = 0; i < N; i++) {
		pair <int, int>temp; //만약 값을 주려면 make_pair(값1,값2)로 선언
		cin >> temp.first >> temp.second;
		if (s[temp.first].empty()) {
			sum++;
			s[temp.first].push(temp.second);
		}
		else { 
			if (temp.second > s[temp.first].top()) {//가장 높은 음만 소리가 남
				s[temp.first].push(temp.second);
				sum++;
			}
			else if (temp.second == s[temp.first].top()) //이미 존재
				continue;
			else { //temp.second가 제일 높은 음이 나도록
				while (!s[temp.first].empty() && temp.second < s[temp.first].top()) {
					s[temp.first].pop();
					sum++;
				} //이미 temp가 존재하면 추가할 필요없음
				if (!s[temp.first].empty() && s[temp.first].top() == temp.second)
					continue;
				s[temp.first].push(temp.second);
				sum++;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
