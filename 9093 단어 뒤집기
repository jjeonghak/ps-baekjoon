#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int n;
	string a;
	cin >> n;
	cin.ignore(); //입력 버퍼 제거
	for(int i=0;i<n;i++){
		getline(cin,a);
		for (int i = 0; i <= a.length(); i++) {
			if (a[i] == ' '||i==a.length()) {
				int j = i - 1;
				while (1) {
					printf("%c", a[j]);
					if (j == 0) {
						printf(" ");
						break;
					}
					if (a[j] == ' ') break;
					j--;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
