#include<iostream>
using namespace std;

int arr[1000001];

int ft_get(int x)
{
    if (arr[x] == x) return x;
    return arr[x] = ft_get(arr[x]);
}

void    ft_union(int a, int b)
{
    a = ft_get(a);
    b = ft_get(b);
    if (a < b) arr[b] = a;
    else arr[a] = b;
}

int ft_find(int a, int b)
{
    a = ft_get(a);
    b = ft_get(b);
    return (a == b);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        if (a == 0) ft_union(b, c);
        else 
        {
            if (ft_find(b, c)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
