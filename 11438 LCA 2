#include<iostream>
#include<vector>
#include<queue>
#define MAX 17
using namespace std;

int n, k;
int depth[100001];
int dp[100001][MAX + 1];
vector<int> v[100001];

void    bfs()
{
    queue<int> q;
    
    q.push(1);
    depth[1] = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < v[current].size(); i++)
        {
            if (depth[v[current][i]] == 0)
            {
                depth[v[current][i]] = depth[current] + 1;
                dp[v[current][i]][0] = current;
                q.push(v[current][i]);
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

int lca(int x, int y)
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
            
    if (x == y) return x;
    
    for (int i = MAX; i >= 0; i--)
    {
        if (dp[x][i] != dp[y][i])
        {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs();
    set_dp();
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}
