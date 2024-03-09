#include<iostream>
#include<queue>
#include<vector>
#define MAX 16
using namespace std;

int n, m;
int dp[40001][MAX + 1];
int depth[40001];
vector<pair<int, int>> v[40001];
long long   cost[40001];

void    bfs()
{
    queue<pair<int, int>> q;
    
    q.push({1, 0});
    depth[1] = 1;
    while (!q.empty())
    {
        int current = q.front().first;
        long long   totalCost = q.front().second;
        q.pop();
        
        for (int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i].first;
            int nextCost = v[current][i].second;
            if (depth[next] == 0)
            {
                depth[next] = depth[current] + 1;
                cost[next] = totalCost + nextCost;
                dp[next][0] = current;
                q.push({next, cost[next]});
            }
        }
    }
    return ;
}

void    set_dp()
{
    for (int i = 1; i < MAX; i++)
        for (int j = 1; j <= n; j++)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
    return ;
}

long long   lca(int x, int y)
{
    if (depth[x] > depth[y])
    {
        int temp = x;
        x = y;
        y = temp;
    }
    for (int i = MAX; i >= 0; i--)
        if (depth[y] - depth[x] >= (1 << i))
            y = dp[y][i];
    if (x == y) return 2 * cost[x];
    for (int i = MAX; i >= 0; i--)
    {
        if (dp[x][i] != dp[y][i])
        {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return 2 * cost[dp[x][0]];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    bfs();
    set_dp();
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        
        cin >> x >> y;
        cout << cost[x] + cost[y] - lca(x, y) << '\n';
    }
    return 0;
}
