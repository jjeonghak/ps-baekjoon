#include<iostream>
#include<stack>
using namespace std;
char a;
stack<int> s1, s2, res;

int main(void) {
	while (1) {
		a = cin.get();
		if (a == ' ') break;
		else s1.push((int)a - 48);
	}
	while (1) {
		a = cin.get();
		if (a == '\n') break;
		else s2.push((int)a - 48);
	}
	int b = 0;
	while (1) {
		int temp;
		if (s1.empty() && s2.empty()) {
			if(b==1) res.push(b);
			break;
		}
		else if (s1.empty()) {
			temp = s2.top() + b;
			if (temp >= 10) b = 1;
			else b = 0;
			s2.pop();
			res.push(temp % 10);
		}
		else if (s2.empty()) {
			temp = s1.top() + b;
			if (temp >= 10) b = 1;
			else b = 0;
			s1.pop();
			res.push(temp % 10);
		}
		else {
			temp = s1.top() + s2.top() + b;
			if (temp >= 10) b = 1;
			else b = 0;
			s1.pop();
			s2.pop();
			res.push(temp % 10);
		}
	}
	while (!res.empty()) {
		cout << res.top();
		res.pop();
	}
	return 0;
}
