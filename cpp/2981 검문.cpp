#include<iostream>
#include<algorithm> //unique(), sort() 포함 
#include<vector>
using namespace std;

int gcd(int a, int b) {
	int c = a % b;
	if (c == 0) return b;
	else return gcd(b, c);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long a[101];
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int k = a[1] - a[0]; //연속하는 두 수의 차이의 최대공약수의 약수들이 답
	for (int i = 2; i < n; i++) {
		k = gcd(k, a[i] - a[i - 1]);
	}
	for (int i = 2; i * i <= k; i++) { //최대공약수의 약수
		if (k % i == 0) {
			v.push_back(i); //절반만 참색하고 나머지는 나누기 연산으로 
			v.push_back(k / i);
		}
	}
	v.push_back(k); //최대공약수도 포함
	sort(v.begin(), v.end()); //중복제거를 위한 정렬
	v.erase(unique(v.begin(), v.end()), v.end()); //벡터 중복제거
	for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
	return 0;
}
