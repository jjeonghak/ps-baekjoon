#include<iostream>
#include<algorithm>
using namespace std;

char arr[26];
bool al[16];
char sol[16];
int m;
int l, c, fj, sj;

void bt(int cnt, int start) {
	if (cnt == l) {
		if (sj!=0 && m!=0) {
			for (int i = 0; i < l; i++) {
				printf("%c", sol[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int i = start; i < c; i++) {
		if (!al[i]) {
			al[i] = true;
			sol[cnt] = arr[i];
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') m++;
			else if (fj==0) fj++;
			else sj++;
			cnt++;
			bt(cnt, i);
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') m--;
			else if (sj != 0) sj--;
			else fj--;
			cnt--;
			al[i] = false;
		}
	}
}

int main(void) {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);
	bt(0, 0);
	return 0;
}
