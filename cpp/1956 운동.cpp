#include<iostream>
#include<algorithm>
#include<vector>
#define INF 2100000000
using namespace std;

int v, e;
int dp[401][401];
vector<pair<int, int>> path[401];

void    set_dp()
{
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            if (!dp[i][j] && i != j) dp[i][j] = INF;
}

int floyd()
{
    int ans = INF;
    
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                if (dp[i][k] != INF && dp[k][j] != INF) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            if (i != j && dp[i][j] != INF && dp[j][i] != INF) ans = min(ans, dp[i][j] + dp[j][i]);
    return ans == INF ? -1 : ans;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        path[a].push_back({b, c});
        dp[a][b] = c;
    }
    set_dp();
    cout << floyd();
    return 0;
}
