#include<iostream>
using namespace std;

int parent[100001];
long long   weight[100001];

void    init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        weight[i] = 0;
    }
    return ;
}

int ft_get(int a)
{
    if (a == parent[a]) return a;
    int temp = ft_get(parent[a]);
    weight[a] += weight[parent[a]];
    return parent[a] = temp;
}

void    ft_union(int a, int b, long long c)
{
    int pa = ft_get(a);
    int pb = ft_get(b);
    if (pa != pb)
    {
        parent[pa] = pb;
        weight[pa] = weight[b] - weight[a] + c;
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
        int n, m;
        
        cin >> n >> m;
        if (n == 0 && m == 0) break ;
        init(n);
        for (int i = 0; i < m; i++)
        {
            char    a;
            int     b, c;
        
            cin >> a >> b >> c;
            if (a == '!')
            {
                long long   d;
                
                cin >> d;
                ft_union(b, c, d);
            }
            else if (a == '?')
            {
                if (ft_get(b) == ft_get(c)) cout << weight[b] - weight[c] << '\n';
                else cout << "UNKNOWN\n";
            }
        }
    }
    return 0;
}
