#include<iostream>
#define INF 2100000000
using namespace std;

int n, flag;
int w[16][16];
int dp[16][(1 << 16)];

int dfs(int m, int bit)
{
    if (bit == flag)
    {
        if (w[m][0] == 0) return INF;
        else return w[m][0];
    }
    if (dp[m][bit] != INF) return dp[m][bit];
    for (int i = 0; i < n; i++)
    {
        if (w[m][i] == 0) continue;
        if ((bit & (1 << i)) > 0) continue;
        dp[m][bit] = min(dp[m][bit], dfs(i, (bit | (1 << i))) + w[m][i]);
    }
    return dp[m][bit];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
    flag = (1 << n) - 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= flag; j++)
            dp[i][j] = INF;
    cout << dfs(0, 1) << '\n';
    return 0;
}
