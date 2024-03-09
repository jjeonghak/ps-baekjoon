#include<iostream>
#include<deque> //앞뒤로 삽입 또는 제거 가능
using namespace std;

int main(void) {
	deque<int>dq;
	int n,k;
	string a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == "push_back") {
			cin >> k;
			dq.push_back(k);
		}
		else if (a == "push_front") {
			cin >> k;
			dq.push_front(k);
		}
		else if (a == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << endl;
				dq.pop_front();
			}
			else cout << "-1" << endl;
		}
		else if (a == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << endl;
				dq.pop_back();
			}
			else cout << "-1" << endl;
		}
		else if (a == "size") cout << dq.size() << endl;
		else if (a == "front") {
			if (!dq.empty()) {
				cout << dq.front() << endl;
			}
			else cout << "-1" << endl;
		}
		else if (a == "back") {
			if (!dq.empty()) {
				cout << dq.back() << endl;
			}
			else cout << "-1" << endl;
		}
		else cout << dq.empty() << endl;
	}
	return 0;
}
