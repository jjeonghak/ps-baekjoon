#include<iostream>

using namespace std;

int dp[1000000];

int sol(int n)
{
    if (n == 1) return 0;
    else if (dp[n] != 0) return dp[n];
    dp[n] = 1000000001;
    if (n % 3 == 0) dp[n] = sol(n / 3) + 1;
    if (n % 2 == 0) dp[n] = min(dp[n], sol(n / 2) + 1);
    return dp[n] = min(dp[n], sol(n - 1) + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    
    cin >> n;
    cout << sol(n);
    return 0;
}
