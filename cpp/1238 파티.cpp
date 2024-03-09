#include<iostream>
#include<vector>
#include<queue>
#define INF 1000000000
using namespace std;

int n, m, x;
int dp[1001][2];
int visit[1001][2];
vector<pair<int, int>> path[1001][2];

void    dijkstra(int flag)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    dp[x][flag] = 0;
    while (!pq.empty())
    {
        int current = pq.top().second;
        int total = -pq.top().first;
        visit[current][flag] = 1;
        pq.pop();
        
        for (int i = 0; i < path[current][flag].size(); i++)
        {
            int next = path[current][flag][i].first;
            int cost = total + path[current][flag][i].second;
            if (!visit[next][flag] && dp[next][flag] > cost)
            {
                dp[next][flag] = cost;
                pq.push({-cost, next});
            }
        }
    }
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        path[a][0].push_back({b, c});
        path[b][1].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = INF;
        dp[i][1] = INF;
    }
    dijkstra(1);
    dijkstra(0);
    int ans = -1;
    for (int i = 1; i <= n; i++)
        if (i != x && dp[i][0] + dp[i][1] > ans) ans = dp[i][0] + dp[i][1];
    cout << ans;
    return 0;
}
