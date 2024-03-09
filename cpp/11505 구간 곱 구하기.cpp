#include<iostream>
#define mod 1000000007
using namespace std;

int n, m, k, b;
long long   indexTree[1 << 22];

long long   set_tree(int index)
{
    if (b < index)
    {
        if (index < b + n)
            return indexTree[index];
        return 1;
    }
    indexTree[index] = (set_tree(2 * index) % mod) * (set_tree(2 * index + 1) % mod) % mod;
    return indexTree[index];
}

void    update_tree(int index, int change)
{
    indexTree[index] = (long long)change;
    while (index > 1)
    {
        if (index % 2 == 1)
            indexTree[index / 2] = indexTree[index] * indexTree[index - 1] % mod;
        else
            indexTree[index / 2] = indexTree[index] * indexTree[index + 1] % mod;
        index /= 2;
    }
    return ;
}

void    search_tree(int lb, int rb, long long ans)
{
    if (lb > rb)
    {
        cout << ans << '\n';
        return ;
    }
    if (lb % 2 == 1) ans = ans * indexTree[lb] % mod;
    if (rb % 2 == 0) ans = ans * indexTree[rb] % mod;
    search_tree((lb + 1) / 2, (rb - 1) / 2, ans);
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    for (b = 1; b < n; b <<= 1);
    for (int i = 0; i < n; i++)
    {
        long long   index;
        
        cin >> index;
        indexTree[b + i] = index;
    }
    set_tree(1);
    for (int i = 0; i < m + k; i++)
    {
        int x, y, z;
        
        cin >> x >> y >> z;
        if (x == 1)
            update_tree(b + y - 1, z);
        else
            search_tree(b + y - 1, b + z - 1, 1);
    }
    return 0;
}
