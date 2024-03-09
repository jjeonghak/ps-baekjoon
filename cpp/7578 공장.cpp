#include<iostream>
using namespace std;

int n;
int arrA[500001];
int arrB[1000001];
int indexTree[1 << 20];
long long ans;

void    ft_update(int index)
{
    if (index == 0) return ;
    indexTree[index]++;
    ft_update(index / 2);
    return ;
}

void    ft_sum(int lb, int rb)
{
    if (lb > rb) return ;
    else if (lb % 2 == 1) ans += indexTree[lb];
    else if (rb % 2 == 0) ans += indexTree[rb];
    ft_sum((lb + 1) / 2, (rb - 1) / 2);
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0) cin >> arrA[j];
            else
            {
                int index;
                
                cin >> index;
                arrB[index] = j;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ft_sum((1 << 19), (1 << 19) + arrB[arrA[i]]);
        ft_update((1 << 19) + arrB[arrA[i]]);
    }
    cout << ans;
    return 0;
}
