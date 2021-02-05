#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<char> v;

int main(void) {
	string a;
	getline(cin, a);
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= 'a' && a[i] <= 'z') {
			char c = a[i];
			if (c < 110) {
				c += 13;
			}
			else c -= 13;
			v.push_back(c);
		}
		else if (a[i] >= 'A' && a[i] <= 'Z') {
			char c = a[i];
			if (c < 78) {
				c += 13;
			}
			else c -= 13;
			v.push_back(c);
		}
		else v.push_back(a[i]);
	}
	vector<char>::iterator j;
	for (j = v.begin(); j != v.end(); j++) {
		cout << *j;
	}
	return 0;
}
