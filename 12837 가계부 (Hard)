#include<iostream>

using namespace std;

int n, q, b;
long long   indexTree[1 << 21];

void    set_tree(int index, long long indexValue)
{
    indexTree[index] += indexValue;
    while (index /= 2)
        indexTree[index] += indexValue;
    return ;
}

void    search_tree(int lb, int rb, long long ans)
{
    if (lb > rb)
    {
        cout << ans << '\n';
        return ;
    }
    if (lb % 2 == 1) ans += indexTree[lb];
    if (rb % 2 == 0) ans += indexTree[rb];
    search_tree((lb + 1) / 2, (rb - 1) / 2, ans);
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    for (b = 1; b < n; b <<= 1);
    for (int i = 0; i < q; i++)
    {
        long long   x, y, z;
        
        cin >> x >> y >> z;
        if (x == 1)
            set_tree(b + y - 1, z);
        else
            search_tree(b + y - 1, b + z - 1, 0);
    }
    return 0;
}
