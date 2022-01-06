#include<iostream>
using namespace std;

int n, ans;
int candy[1 << 22 + 1];

void    ft_add_candy(int index, int c)
{
    if (index == 0) return ;
    candy[index] += c;
    ft_add_candy(index / 2, c);
    return ;
}

void    ft_sub_candy(int index, int rank)
{
    if (index >= 1 << 22) 
    {
        ans = (index >> 1) - (1 << 21) + 1;
        return ;
    }
    if (rank <= candy[index * 2]) ft_sub_candy(index * 2, rank);
    else ft_sub_candy(index * 2 + 1, rank - candy[index * 2]);
    candy[index]--;
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        
        cin >> a >> b;
        if (a == 1)
        {
            ft_sub_candy(1, b);
            cout << ans << '\n';
        }
        else if (a == 2)
        {
            cin >> c;
            ft_add_candy((1 << 21) + b - 1, c);
        }
    }
    return 0;
}
