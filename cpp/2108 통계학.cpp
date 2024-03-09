//old
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[8002];
vector<int>v;

int main(void) {
	int n, m;
	vector<int>::iterator j;
	cin >> n;
	int temp = 4001;
	int temp1 = -4001;
	double sum = 0;
	int b = 0; //최고빈도
	for (int i = 1; i <= n; i++) {
		cin >> m;
		v.push_back(m);
		a[m + 4000]++;
		b = max(a[m + 4000], b);
		sum += m;
		if (m >= temp1) temp1 = m; //최소
		if (m <= temp) temp = m; //최대
	}
	sort(v.begin(), v.end());
	double ave = sum / n; //산술쳥균
	int ran = temp1 - temp; //범위
	int l = 0; //최빈값
	bool h = true;
	for (int i = 0; i <= 8001; i++) {
		if (a[i] == b && h) {
			l = i-4000;
			h = !h;
		}
		else if (a[i] == b) {
			l = i-4000;
			break;
		}
	}
	printf("%.0lf\n%d\n%d\n%d", ave, v[n / 2], l, ran);
	return 0;
}


//new
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, maxV = -4001, minV = 4001, avg = 0, arrMax = -1;
int arr[8001];
vector<int> v;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int index;
        
        cin >> index;
        if (maxV < index) maxV = index;
        if (minV > index) minV = index;
        avg += index;
        v.push_back(index);
        arr[4000 + index]++;
        if (arrMax < arr[4000 + index]) arrMax = arr[4000 + index];
    }
    sort(v.begin(), v.end());
    int mode, check = 0;
    for (int i = minV + 4000; i <= maxV + 4000; i++)
    {
        if (arrMax == arr[i])
        {
            mode = i - 4000;
            if (check) break ;
            else check = 1;
        }
    }
    if (0.5 <= abs((double)avg / n - avg / n)) 
        avg > 0 ? avg = avg / n + 1 : avg = avg / n - 1;
    else avg = avg / n;
    
    cout << avg << '\n';
    cout << v[n / 2] << '\n';
    cout << mode << '\n';
    cout << maxV - minV;
    return 0;
}
