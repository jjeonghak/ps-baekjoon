#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, k;
pair<int, int> depth[100001];
vector<int> v[100001];

void    bfs()
{
    queue<int> q;
    
    q.push(1);
    depth[1].second = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < v[current].size(); i++)
        {
            if (depth[v[current][i]].second == 0)
            {
                depth[v[current][i]].second = depth[current].second + 1;
                depth[v[current][i]].first = current;
                q.push(v[current][i]);
            }
        }
    }
    return ;
}

int lca(int a, int b)
{
    if (depth[a].second < depth[b].second)
        while (depth[b].second != depth[a].second)
            b = depth[b].first;
    else
        while (depth[a].second != depth[b].second)
            a = depth[a].first;
    while (a != b)
    {
        a = depth[a].first;
        b = depth[b].first;
    }
    return a;
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
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}
