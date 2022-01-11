#include<iostream>
#define INF 1000000000
using namespace std;

int n, m;
int dp[501][501];

void    init()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) dp[i][j] = INF;
    return ;
}

void    floydWarshall()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j]) dp[i][j] = dp[i][k] + dp[k][j];
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
        int a, b;
        
        cin >> a >> b;
        dp[a][b] = 1;
    }
    floydWarshall();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int check = 1;
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] != INF) continue;
            else if (dp[j][i] != INF) continue;
            else check = 0;
        }
        if (check) ans++;
    }
    cout << ans;
    return 0;
}
