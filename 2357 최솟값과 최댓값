#include<iostream>
#include<algorithm>
using namespace std;

int n, m, b;
pair<int, int> indexTree[1 << 18];


int set_tree(int c, int index)
{
    if (c)
    {
        if (b <= index)
            return indexTree[index].first;
        return indexTree[index].first = max(set_tree(c, 2 * index), set_tree(c, 2 * index + 1));
    }
    else
    {
        if (b <= index)
            return indexTree[index].second;
        return indexTree[index].second = min(set_tree(c, 2 * index), set_tree(c, 2 * index + 1));
    }
}

void    search_tree(int c, int lb, int rb, int ans)
{
    if (c)
    {
        if (lb > rb)
        {
            cout << ans << '\n';
            return ;
        }
        if (lb % 2 == 1) ans = max(ans, indexTree[lb].first);
        if (rb % 2 == 0) ans = max(ans, indexTree[rb].first);
        search_tree(c, (lb + 1) / 2, (rb - 1) / 2, ans);
    }
    else
    {
        if (lb > rb)
        {
            cout << ans << ' ';
            return ;
        }
        if (lb % 2 == 1) ans = min(ans, indexTree[lb].second);
        if (rb % 2 == 0) ans = min(ans, indexTree[rb].second);
        search_tree(c, (lb + 1) / 2, (rb - 1) / 2, ans);
    }
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
        indexTree[b + i] = {index, index};
    }
    set_tree(0, 1);
    set_tree(1, 1);
    for (int i = 0; i < m; i++)
    {
        int lb, rb;
        
        cin >> lb >> rb;
        search_tree(0, b + lb - 1, b + rb - 1, 1000000001);
        search_tree(1, b + lb - 1, b + rb - 1, -1);
    }
    return 0;
}
