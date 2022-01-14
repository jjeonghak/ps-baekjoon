#include<iostream>
#include<vector>
using namespace std;

int n;
int index[1000001];
int len[1000001];
vector<int> v;

void    ft_print(int start, int cnt)
{
    if (cnt == 0) return ;
    for (int i = start; i >= 0; i--)
    {
        if (cnt == len[i])
        {
            ft_print(i - 1, cnt - 1);
            cout << index[i] << ' ';
            break ;
        }
    }
    return ;
}

void    ft_sol()
{
    v.push_back(index[0]);
    len[0] = 1;
    for (int i = 1; i < n; i++)
    {
       if (index[i] > v[v.size() - 1])
       {
           v.push_back(index[i]);
           len[i] = v.size();
       }
       else
       {
           int  l = 0, r = v.size() - 1;
           
           while (1)
            {
                if (l >= r) break ;
                int  mid = (l + r) / 2;
                if (v[mid] >= index[i]) r = mid;
                else l = mid + 1;
            }
            v[l] = index[i];
            len[i] = l + 1;
        }
    }
    int cnt = v.size();
    cout << cnt << '\n';
    ft_print(n - 1, cnt);
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> index[i];
    ft_sol();
    return 0;
}
