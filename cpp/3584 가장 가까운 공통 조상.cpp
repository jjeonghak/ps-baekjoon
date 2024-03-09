#include<iostream>
#include<vector>
#include<queue>
#define MAX 14
using namespace std;

int n;
int depth[10001];
int check[10001];
int dp[10001][MAX + 1];
vector<int> v[10001];

int find_start()
{
    int cnt = 0;
    while (++cnt)
        if (!check[cnt]) break ;
    return cnt;
}

void    bfs()
{
    queue<int> q;
    
    int start = find_start();
    q.push(start);
    depth[start] = 1;
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
    
    int t;
    
    cin >> t;
    while (t--)
    {
        int a, b;
        
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
            check[b] = 1;
        }
        cin >> a >> b;
        bfs();
        set_dp();
        cout << lca(a, b) << '\n';
        for (int i = 1; i <= n; i++)
        {
            v[i].clear();
            check[i] = 0;
            depth[i] = 0;
        }
    }
    return 0;
}
