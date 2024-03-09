#include<iostream>
using namespace std;

int n, m;
int a[10];
bool c[10];

void sol(int k) { //k는 자릿수
	if (k == m+1) { //배열 a가 1부터 시작하므로 자릿수 다채움
		for (int i = 1; i < m+1; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!c[i]&&a[k-1]<i) { //이전 재귀에서 미사용시 및 전 자릿수보다 클 경우
			a[k] = i; //다른 값으로 덮힐 예정
			c[i] = true; //들어갈때 사용표시
			sol(k + 1);
			c[i] = false; //과정이 끝난 후 다시 미사용표시
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n >> m;
	sol(1); //배열 a는 0부터 시작하고 k-1비교를 위해
	return 0;
}
