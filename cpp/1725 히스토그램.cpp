#include<iostream>
#include<algorithm>
using namespace std;

int n, b;
pair<int, int> indexTree[1 << 18];
long long   ans;

pair<int, int>  set_tree(int index)
{
    if (b <= index)
        return indexTree[index];
    
    pair<int, int> temp1 = set_tree(2 * index);
    pair<int, int> temp2 = set_tree(2 * index + 1);
    
    if (temp1.first == -1)
        return indexTree[index] = temp2;
    else if (temp2.first == -1)
        return indexTree[index] = temp1;
    else
        return indexTree[index] = min(temp1, temp2);
}

pair<int, int>  search_tree(int lb, int rb, pair<int, int> minIndex)
{
    if (lb > rb)
        return minIndex;
    if (lb % 2 == 1) minIndex = min(minIndex, indexTree[lb]);
    if (rb % 2 == 0) minIndex = min(minIndex, indexTree[rb]);
    return search_tree((lb + 1) / 2, (rb - 1) / 2, minIndex);
}

void    solve(int lb, int rb)
{
    if (lb > rb) return ;
    pair<int, int>  indexValue = search_tree(lb, rb, {1000000001, 0});
    ans = max(ans, (long long)(rb - lb + 1) * indexValue.first);
    solve(lb, indexValue.second - 1);
    solve(indexValue.second + 1,  rb);
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;

    for (b = 1; b < n; b <<= 1);
    for (int i = 0; i < b; i++)
    {
        int h;
            
        if (i < n)
            cin >> h;
        else
            h = -1;
        indexTree[b + i] = {h, b + i};
    }
    set_tree(1);
    solve(b, b + n - 1);
    cout << ans << '\n';
    return 0;
}
