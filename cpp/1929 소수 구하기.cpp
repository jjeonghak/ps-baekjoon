#include<stdio.h> //시간 초과로 인해 scanf, printf 사용
#include<math.h>
using namespace std;

int a[1000001];

int main(void) {
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 2; i < 1000001; i++) {
		a[i] = i;
	}
	int temp = (int)sqrt(n);
	for (int i = 2; i <= temp; i++) {
		if (a[i] == 0) continue;
		else {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] == 0) continue;
				if (a[j] % i == 0) a[j] = 0;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (a[i] != 0) printf("%d\n", a[i]);
	}
	return 0;
}
