#include<iostream>
#include<vector>
#include<queue>
#define INF 210000000
using namespace std;

int n, m;
int arr[1001];
int cost[1001];
vector<pair<int, int>> path[1001];

void    set_cost()
{
    for (int i = 1; i <= n; i++)
        cost[i] = INF;
    return ;
}

int search(int s, int e)
{
    priority_queue<pair<int, int>> pq;
    
    set_cost();
    pq.push({0, 1});
    while (!pq.empty())
    {
        int current = pq.top().second;
        int total = -pq.top().first;
        pq.pop();
        
        for (int i = 0; i < path[current].size(); i++)
        {
            int next = path[current][i].first;
            int nextCost = path[current][i].second;
            
            if (next == 1) continue ;
            else if (!(s == current && e == next) && nextCost + total < cost[next])
            {
                cost[next] = nextCost + total;
                if(s == 0 && e == 0) arr[next] = current;
                pq.push({-cost[next], next});
            }
        }
    }
    return cost[n];
}

int sol()
{
    int cnt = n;
    int ans = search(0, 0);
    
    while (arr[cnt])
    {
        ans = max(ans, search(arr[cnt], cnt));
        cnt = arr[cnt];
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        path[a].push_back({b, c});
        path[b].push_back({a, c});
    }
    cout << sol();
    return 0;
}
