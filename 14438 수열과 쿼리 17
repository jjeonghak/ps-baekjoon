#include<iostream>

using namespace std;

int n, r, m;
int indexTree[1 << 19];

int set_tree(int index)
{
    if (r <= index && index < r + n) return indexTree[index];
    else if (r + n <= index) return 1000000001;
    return indexTree[index] = min(set_tree(2 * index), set_tree(2 * index + 1));
}

void    update_tree(int index, int changeValue)
{
    indexTree[index] = changeValue;
    while (index /= 2)
        indexTree[index] = min(indexTree[2 * index], indexTree[2 * index + 1]);
    return ;
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
    search_tree((lb + 1) >> 1, (rb - 1) >> 1, ans);
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (r = 1; r < n; r <<= 1);
    for (int i = 0; i < n; i++)
    {
        int index;
        
        cin >> index;
        indexTree[r + i] = index;
    }
    set_tree(1);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        if (a == 1)
            update_tree(r + b - 1, c);
        else
            search_tree(r + b - 1, r + c - 1, 1000000001);
    }
    return 0;
}
