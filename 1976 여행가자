#include<iostream>

using namespace std;

int n, m;
int parent[201];

int get_parent(int a)
{
    if (a == parent[a]) return a;
    return get_parent(parent[a]);
}

void    change_parent(int a, int ap)
{
    while (a != ap)
    {
        int temp = parent[a];

        parent[a] = ap;
        a = temp;
    }
    return ;
}

void    union_parent(int a, int b)
{
    int ap = get_parent(a);
    int bp = get_parent(b);
    if (ap != bp) ap < bp ? change_parent(b, ap) : change_parent(a, bp);
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int index;
            
            cin >> index;
            if (index == 1) union_parent(i, j);
        }
    
    int temp = 0;
    while (m--)
    {
        int index;
        
        cin >> index;
        if (temp == 0) temp = get_parent(index);
        else if (temp != get_parent(index) || index > n)
        {
            temp = 0;
            break ;
        }
    }
    if (temp) cout << "YES";
    else cout << "NO";
    return 0;
}
