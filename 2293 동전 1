#include<iostream>
using namespace std;

int cost[101];
int dp[10001];

int solution(int n, int k)
{
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = cost[i]; j <= k; j++)
            dp[j] += dp[j - cost[i]];
    return dp[k];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    cout << solution(n, k);
    return 0;
}
