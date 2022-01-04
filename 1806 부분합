#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s, ans, sum , cnt;
    vector<int> v;
    
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int index;
        
        cin >> index;
        if (index >= s)
        {
            cout << 1;
            return 0;
        }
        v.push_back(index);
    }
    ans = 100001;
    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0)
        {
            sum = v[i];
            cnt = 1;
        }
        else
        {
            sum -= v[i - 1];
            cnt--;
            if (sum >= s)
            {
                if (cnt < ans) ans = cnt;
                continue;
            }
        }
        for (int j = i + cnt; j < n; j++)
        {
            sum += v[j];
            cnt++;
            if (sum >= s) 
            {
                if (cnt < ans) ans = cnt;
                break ;
            }
        }
    }
    if (ans != 100001)
        cout << ans;
    else
        cout << 0;
    return 0;
}
