#include<iostream>
#include<stack>
using namespace std;

int main(void) {
	string b;
	stack<char> r, l;
	char c;
	int m;
	cin >> b >> m;
	for (int i = 0; i < b.length(); i++) {
		l.push(b[i]);
	}
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (c == 'P') {
			cin >> c;
			l.push(c);
		}
		else if (c == 'L') {
			if (l.empty()) continue;
			else {
				r.push(l.top());
				l.pop();
			}
		}
		else if (c == 'D') {
			if (r.empty()) continue;
			else {
				l.push(r.top());
				r.pop();
			}
		}
		else {
			if (l.empty()) continue;
			else l.pop();
		}
	}
	while(!l.empty()) {
		r.push(l.top());
		l.pop();
	}
	while (!r.empty()) {
		printf("%c", r.top());
		r.pop();
	}
	return 0;
}
