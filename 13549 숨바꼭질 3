#include<iostream>
#include<queue>
using namespace std;

int n, k, ans;
int check[200001];

void    sol()
{
    priority_queue<pair<int, int>> q;
    q.push({0, n});
    ans = 2147483647;
    while (!q.empty())
    {
        pair<int, int> index = q.top();
        q.pop();
        if (check[index.second]) continue;
        else if (index.second < k) 
        {
            if (index.second != 0) q.push({index.first, 2 * index.second});
            q.push({-(-index.first + 1), index.second + 1});
            if (index.second > 1) q.push({-(-index.first + 1), index.second - 1});
        }
        else ans = min(ans, -index.first + index.second - k);
        if (index.second != k) check[index.second] = 1;
    }
    return ;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    sol();
    cout << ans;
    return 0;
}
