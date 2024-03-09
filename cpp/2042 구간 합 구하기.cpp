#include<iostream>
using namespace std;

int n, m, k;
long long indexTree[6000001];

long long ft_set(long long max, long long index)
{
    if (index >= max) return 0;
    if (indexTree[index] == 0)
        indexTree[index] = ft_set(max, index * 2) + ft_set(max, index * 2 + 1);
    return indexTree[index];
}

void    ft_change(long long index, long long newIndex)
{
    if (index == 0) return ;
    indexTree[index] = newIndex;
    ft_change(index / 2, newIndex + indexTree[index % 2 == 0 ? index + 1 : index - 1]);
    return ;
}

void    ft_print(long long lb, long long rb, long long sum)
{
    if (lb > rb) 
    {
        cout << sum << '\n';
        return ;
    }
    if (lb % 2 == 1) sum += indexTree[lb];
    if (rb % 2 == 0) sum += indexTree[rb];
    ft_print((lb + 1) / 2, (rb - 1) / 2, sum);
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long r = 1, sum = 1;
    
    cin >> n >> m >> k;
    while (1)
    {
        r *= 2;
        if (r >= n) break ;
        sum += r;
    }
    for (int i = 0; i < n; i++)
    {
        long long index;
        
        cin >> index;
        indexTree[sum + i] = index;
    }
    ft_set(sum * 2, 1);
    for (int i = 0; i < m + k; i++)
    {
        long long a, b, c;
        
        cin >> a >> b >> c;
        if (a == 1) ft_change(sum + b - 1, c);
        else ft_print(sum + b - 1, sum + c - 1, 0);
    }
    return 0;
}
