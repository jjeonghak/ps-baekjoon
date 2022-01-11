#include<iostream>
#define INF 100000000
using namespace std;

int dp[101][101];
int n, m;

void    init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            else dp[i][j] = INF;
        }
    }
    return ;
}

void    floydWarshall()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < dp[a][b]) dp[a][b] = c;
    }
    floydWarshall();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] == INF) cout << "0 ";
            else cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
