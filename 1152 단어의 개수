#include<iostream>
#include<string>
using namespace std;
char a[1000001];

int main(void) {
	int i = 0;
	int sum = 0;
	while (1) {
		a[i] = cin.get();
		if (i!=0&&a[i] == ' ') sum++;
		else if (a[i] == '\n') {
			if (a[i - 1] == ' ') break;
			else {
				sum++;
				break;
			}
		}
		i++;
	}
	cout << sum;
	return 0;
}
