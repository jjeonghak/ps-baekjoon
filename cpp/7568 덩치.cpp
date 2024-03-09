#include<iostream>
using namespace std;

int main(void) {
	int n;
	int w, h;
	
	pair<int, int>p[50];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w >> h;
		p[i].first = w;
		p[i].second = h;
	}
	for (int i = 0; i < n; i++) {
		int j = 0;
		int k = 1;
		while (j != n ) {
			if (p[i].first < p[j].first && p[i].second < p[j].second) k++;
			j++;
		}
		cout << k << " ";
	}
	return 0;
}
