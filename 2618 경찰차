#include<iostream>
using namespace std;

int n, w;
int dp[1001][1001];
int locate[1001][2];

int ft_cal_distance(int flag, int p1, int p2)
{
    int x1, y1, x2, y2;
    
    x1 = locate[p1][0];
    y1 = locate[p1][1];
    x2 = locate[p2][0];
    y2 = locate[p2][1];
    if (p2 == 0)
    {
        if (flag)
        {
            x2 = 1;
            y2 = 1;
        }
        else
        {
            x2 = n;
            y2 = n;
        }
    }
    return abs(x1 - x2) + abs(y1 - y2);
}

int ft_sol(int p1, int p2)
{
    if (p1 == w || p2 == w) return 0;
    if (dp[p1][p2] > 0) return dp[p1][p2];
    int next = max(p1, p2) + 1;
    
    int temp1 = ft_sol(next, p2) + ft_cal_distance(1, next, p1);
    int temp2 = ft_sol(p1, next) + ft_cal_distance(0, next, p2);
    
    return dp[p1][p2] = min(temp1, temp2);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> w;
    for (int i = 1; i <= w; i++)
        cin >> locate[i][0] >> locate[i][1];
    
    cout << ft_sol(0, 0) << '\n';
    int p1 = 0, p2 = 0;
    for (int i = 1; i <= w; i++)
    {
        int distance = ft_cal_distance(1, i, p1);
        if ((dp[p1][p2] - dp[i][p2]) == distance)
        {
            p1 = i;
            cout << "1" << '\n';
        }
        else
        {
            p2 = i;
            cout << "2" << '\n';
        }
    }
    return 0;
}
