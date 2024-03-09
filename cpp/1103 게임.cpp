#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int dp[51][51];
int map[51][51];
int check[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int ft_check(int x, int y)
{
    if (0 <= x && x < n && 0 <= y && y < m)
        return 1;
    return 0;
}

int sol(int x, int y)
{
    if (dp[x][y] != 0 || map[x][y] == -1)
        return dp[x][y];
    for (int i = 0; i < 4; i++)
    {
        int nx = x + map[x][y] * dx[i];
        int ny = y + map[x][y] * dy[i];
        if (ft_check(nx, ny))
        {
            if (check[nx][ny] == 1)
            {
                cout << -1 << '\n';
                exit(0);
            }
            check[nx][ny] = 1;
            dp[x][y] = max(dp[x][y], sol(nx, ny));
            check[nx][ny] = 0;
        }
    }
    dp[x][y]++;
    return dp[x][y];
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int result;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char    c;
            
            cin >> c;
            if (c == 'H')
                map[i][j] = -1;
            else
                map[i][j] = c - '0';
        }
    }
    result = sol(0, 0);
    cout << result << '\n';
    return 0;
}
