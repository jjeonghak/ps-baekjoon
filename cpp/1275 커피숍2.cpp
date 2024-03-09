#include<iostream>

using namespace std;
long long   sum;
long long   indexTree[2 << 17];

long long   ft_set(int index)
{
    if (index >= 2 << 16) return indexTree[index];
    else indexTree[index] = ft_set(index * 2) + ft_set(index * 2 + 1);
    return indexTree[index];
}

void    ft_sum(int lb, int rb)
{
    if (lb > rb) return;
    if (lb % 2 == 1) sum += indexTree[lb];
    if (rb % 2 == 0) sum += indexTree[rb];
    ft_sum((lb + 1) / 2, (rb - 1) / 2);
    return ;
}

void    ft_update(int index, long long diff)
{
    if (index == 0) return ;
    indexTree[index] += diff;
    ft_update(index / 2, diff);
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> indexTree[(2 << 16) + i];
    ft_set(1);
    for (int i = 0; i < q; i++)
    {
        int lb, rb, index, newIndex;
        
        cin >> lb >> rb >> index >> newIndex;
        sum = 0;
        if (lb < rb) ft_sum((2 << 16) + lb, (2 << 16) + rb);
        else ft_sum((2 << 16) + rb, (2 << 16) + lb);
        cout << sum << '\n';
        ft_update((2 << 16) + index, newIndex - indexTree[(2 << 16) + index]);
    }
    return 0;
}
