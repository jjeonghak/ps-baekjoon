#include<iostream>
#include<queue>
using namespace std;

int n, m, ans;
int arr[1001];

class Edge
{
public:
    int node1;
    int node2;
    int cost;
    Edge(int a, int b, int c) : node1(a), node2(b), cost(c) {}
    bool operator < (const Edge other) const
    {
        return this->cost > other.cost;
    }
};

priority_queue<Edge> pq;

int get(int x)
{
    if (arr[x] == x) return x;
    return arr[x] = get(arr[x]);
}

void    ft_union(int x, int y)
{
    x = get(x);
    y = get(y);
    if (x > y) arr[x] = arr[y];
    else arr[y] = arr[x];
    return ;
}

int find(int x, int y)
{
    int a = get(x);
    int b = get(y);
    return (a == b);
}

void    ft_sol()
{
    int cnt;
    
    cnt = 0;
    while (cnt != n - 1)
    {
        Edge node = pq.top();
        pq.pop();
        if (!find(node.node1, node.node2))
        {
            ans += node.cost;
            cnt++;
            ft_union(node.node1, node.node2);
        }
    }
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        pq.push(Edge(a, b, c));
    }
    ft_sol();
    cout << ans;
    return 0;
}
