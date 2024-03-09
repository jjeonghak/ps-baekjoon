#include<iostream>
#include<algorithm>
using namespace std;

int n, m, b;
int indexTree[1 << 18];

int set_tree(int index)
{
    if (b <= index)
        return indexTree[index];
    return indexTree[index] = min(set_tree(2 * index), set_tree(2 * index + 1));
}

void    search_tree(int lb, int rb, int ans)
{
    if (lb > rb)
    {
        cout << ans << '\n';
        return ;
    }
    if (lb % 2 == 1) ans = min(ans, indexTree[lb]);
    if (rb % 2 == 0) ans = min(ans, indexTree[rb]);
    search_tree((lb + 1) / 2, (rb - 1) / 2, ans);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (b = 1; b < n; b <<= 1);
    for (int i = 0; i < n; i++)
    {
        int index;
        
        cin >> index;
        indexTree[b + i] = index;
    }
    set_tree(1);
    for (int i = 0; i < m; i++)
    {
        int lb, rb;
        
        cin >> lb >> rb;
        search_tree(b + lb - 1, b + rb - 1, 1000000001);
    }
    return 0;
}
