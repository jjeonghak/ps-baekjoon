#include<iostream>

using namespace std;

int dp[201][101];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    
    cin >> n >> m >> k;
    n += m;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= i && j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            if (dp[i][j] > 1000000000) dp[i][j] = 1000000001;
        }
    }
    if (dp[n][m] < k) cout << "-1";
    else
    {
        while (n)
        {
            if (dp[n - 1][m] >= k) cout << "a";
            else
            {
                cout << "z";
                k -= dp[n - 1][m--];
            }
            n--;
        }
    }
    return 0;
}
