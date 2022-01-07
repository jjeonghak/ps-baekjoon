#include<iostream>

using namespace std;

int map[1002][1002];
int dp[1002][1002];

int main(void)
{
    int h, w, n;
    
    cin >> h >> w >> n;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> map[i][j];
            
    dp[1][1] = n - 1;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[i + 1][j] += dp[i][j] / 2;
            dp[i][j + 1] += dp[i][j] / 2;
            if (dp[i][j] % 2 == 1)
            {
                if (map[i][j] == 0) dp[i + 1][j]++;
                else dp[i][j + 1]++;
            }
            map[i][j] = (map[i][j] + dp[i][j]) % 2;
        }
    }
    int r = 1, c = 1;
    while(r <= h && c <= w)
    {
        if (map[r][c] == 1) c++;
        else r++;
    }
    cout << r << ' ' << c;
    return 0;
}
