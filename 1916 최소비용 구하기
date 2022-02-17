#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int totalCost[1001];
vector<pair<int, int>> path[1001];

void    solution(int s, int e)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    for (int i = 1; i <= n; i++)
        if (i != s) totalCost[i] = 1000000001;
    while (!pq.empty())
    {
        int current = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        if (totalCost[current] < cost) continue;
        for (int i = 0; i < path[current].size(); i++)
        {
            int next = path[current][i].second;
            int nextCost = cost + path[current][i].first;
            if (nextCost < totalCost[next])
            {
                totalCost[next] = nextCost;
                pq.push({-nextCost, next});
            }
        }
    }
    cout << totalCost[e];
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int c;
        
        cin >> a >> b >> c;
        path[a].push_back({c, b});
    }
    cin >> a >> b;
    solution(a, b);
    return 0;
}
