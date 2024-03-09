#include <iostream>

using namespace std;

int n, k;
long long Answer;
long long s[500001];
int dp[500001];

long long comb(int m) {
    long long result = 1;
    int r = (m - k + 1 < k - 1 ? m - k + 1 : k - 1);
    for (long long i=1;i<=(long long)r;i++) {
        result *= (m - i + 1);
        result /= i;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    dp[0] = 1;
	Answer = 0;
	
	cin >> n;
	k = 4;
	for (int i=1;i<=n;i++) {
	    long long index;
	    
	    cin >> index;
	    s[i] = s[i - 1] + index;
	}
    if (s[n] % k <= 0) {
        if (s[n] == 0) {
	        int zeroCnt = 0;
	        for (int i=1;i<=n;i++)
	            if (s[i] == 0) zeroCnt++;
	        Answer = comb(zeroCnt - 1);
        }
        else {
            long long d = s[n] / k;
            for (int i=1;i<=k;i++)
                dp[i] = 0;
            for (int i=1;i<=n;i++) {
                long long index = s[i] / d;
                if (s[i] % d == 0 && index < k && index > 0)
                    dp[index] += dp[index - 1];
            }
            Answer = dp[k - 1];
        }
    }
	cout << Answer << endl;
	return 0;
}
