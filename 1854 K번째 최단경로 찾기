#include<iostream>
#include<vector>
#include<queue>
using namespace std;

priority_queue<int> length[1001];
vector<pair<int, int>> v[1001];

int n, m, k;

void    sol()
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    length[1].push(0);
    while (!pq.empty())
    {
        int current = pq.top().second;
        int total = -pq.top().first;
        pq.pop();
        for (int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i].first;
            int cost = v[current][i].second + total;
            
            if (length[next].size() < k)
            {
                length[next].push(cost);
                pq.push({-cost, next});
            }
            else if (length[next].top() > cost)
            {
                length[next].pop();
                length[next].push(cost);
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
    
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    sol();
    for (int i = 1; i <= n; i++)
    {
        if (length[i].size() < k) cout << "-1\n";
        else cout << length[i].top() << '\n';
    }
    return 0;
}
