#include<iostream>
#include<deque>
using namespace std;

int arr[100001];

int main(void) {
	int t, n, m;
	char a;
	string s;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t != 0) {
		bool b = true, c = true; //오류와 빼는 순서
		deque<int>dq;
		cin >> s;
		cin >> n;
		if (n == 0) {
			for (int i = 0; i < 2; i++) {
				cin >> a;
			}
		}
		else {
			for (int i = 0; i < n + 1; i++) {
				if (i == n) cin >> a;
				else {
				cin >> a >> m;
				dq.push_back(m);
				}
			}
		}
		for (int i = 0; i < s.length(); i++) {
				if (s[i] == 'D') {
					if (dq.empty()) {
						b = !b; //error 상태 
						break;
					}
					else if (c) dq.pop_front(); //빼는 순서가 정방향
					else dq.pop_back(); //역방향
				}
				else if (s[i] == 'R') {
					c = !c; //이렇게 안하고 매번 배열순서 변경시 시간초과
				}
		}
		if (!c && b) { //최종적인 배열이 역순일 경우 배열순서 변경
			int temp1 = dq.size();
			for (int i = 1; i < temp1; i++) { 
				arr[i] = dq.front();
				dq.pop_front();
			}
			for (int i = temp1 - 1; i > 0; i--) {
				dq.push_back(arr[i]);
			}
		}
		int temp = dq.size();
		if (b == false) printf("error\n");
		else {
			for (int i = 0; i <= 2 * temp; i++) {
				if (temp == 0) {
					printf("[]\n");
					break;
				}
				else {
					if (i == 0) printf("[");
					else if (i == 2 * temp) printf("]\n");
					else if (i % 2 == 0) printf(",");
					else {
						printf("%d",dq.front());
						dq.pop_front();
					}
				}
			}
		}	
		t--;
	}
	return 0;
}
