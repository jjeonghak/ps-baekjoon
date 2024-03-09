#include<stdio.h>
char str[1000]; //입력 받는 화학식 배열
int i; //배열을 순회할 인덱스

int sol() { //괄호 단위로 화학식량 계산
	int m = 0;
	while (1) //반복문으로 str[i]확인. while문 밖에서 return m
	{
		if (str[i] == 0) break; //문자열 종료시 m 증가도 종료

		if (str[i] == '(') { //여는 괄호 만날시
			i++; //괄호 다음 인덱스로 이동
			m += sol(); //제귀호출, 방금 만난 괄호의 화학식량을 구해서 더함
		}
		if (str[i] == ')') {//닫는 괄호 만날시
			i++;
			if ('0' < str[i] && str[i] <= '9') { //괄호 옆에 숫자가 있다면
				m = m * (str[i] - '0'); //(괄호 안의 화학식량)*(옆 숫자)
				i++;
			}
			return m; //m은 괄호의 총 화학식량을 가지고 있다
		}
		if (str[i] == 'C') {
			i++;
			if ('0' < str[i] && str[i] <= '9') { //탄소 옆 숫자가 있다면
				m += 12 * (str[i] - '0');
				i++;
			}
			else m += 12; //탄소 옆 숫자가 없다면 12만 추가
		}
		else if (str[i] == 'H') {
			i++;
			if ('0' < str[i] && str[i] <= '9') {
				m += 1 * (str[i] - '0');
				i++;
			}
			else m += 1;
		}
		else if (str[i] == 'O') {
			i++;
			if ('0' < str[i] && str[i] <= '9') {
				m += 16 * (str[i] - '0');
				i++;
			}
			else m += 16;
		}
	}
	return m; //while문 종료시 지금까지 구한 화학식량 리턴
}

int main(void) {
	scanf("%s", str);
	printf("%d", sol());
}
