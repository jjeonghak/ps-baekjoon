#include<iostream>
#include<vector>
#include<queue>
#define INF 2100000000
using namespace std;

int checkEdge[501][501];
int dis[501];
vector<pair<int, int>>  path[501];
vector<int> prenode[501];

void    sol(int flag, int s, int d)
{
    int check = 0;
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, s});
    dis[s] = 0;
    while (!pq.empty())
    {
        int current = pq.top().second;
        int total = -pq.top().first;
        pq.pop();
        for (int i = 0; i < path[current].size(); i++)
        {
            int next = path[current][i].first;
            int cost = path[current][i].second + total;
            
            if (checkEdge[current][next]) continue ;
            if (dis[next] > cost)
            {
                dis[next] = cost;
                pq.push({-cost, next});
                if (flag)
                {
                    prenode[next].clear();
                    prenode[next].push_back(current);
                }
            }
            else if (flag && dis[next] == cost) prenode[next].push_back(current);
        }
    }
    return ;
}

void    removePath(int d)
{
    for (int i = 0; i < prenode[d].size(); i++)
    {
        if (checkEdge[prenode[d][i]][d]) continue ;
        checkEdge[prenode[d][i]][d] = 1;
        removePath(prenode[d][i]);
    }
    return ;
}

void    init(int n)
{
    for (int i = 0; i < n; i++)
    {
        path[i].clear();
        prenode[i].clear();
        dis[i] = INF;
        for (int j = 0; j < n; j++)
            checkEdge[i][j] = 0;
    }
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while (1)
    {
        int n, m, s, d;
        
        cin >> n >> m;
        if (n == 0 && m == 0) break ;
        init(n);
        cin >> s >> d;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            
            cin >> a >> b >> c;
            path[a].push_back({b, c});
        }
        sol(1, s, d);
        if (dis[d] == INF) 
            cout << "-1\n";
        else
        {
            removePath(d);
            for (int i = 0; i < n; i++)
                dis[i] = INF;
            sol(0, s, d);
            if (dis[d] == INF) cout << "-1\n";
            else cout << dis[d] << '\n';
        }
    }
    return 0;
}
