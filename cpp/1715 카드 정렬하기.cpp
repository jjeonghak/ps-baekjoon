#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, ans;
    priority_queue<int> pq;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int index;
        
        cin >> index;
        pq.push(-index);
    }
    ans = 0;
    while (!pq.empty())
    {
        int index1 = -pq.top();
        ans += index1;
        pq.pop();
        if (pq.size() > 1)
        {
            int index2 = -pq.top();
            ans += index2;
            pq.pop();
            pq.push(-(index1 + index2));
        }
    }
    if (n != 1) cout << ans;
    else cout << 0;
    return 0;
}
