#include<iostream>
using namespace std;

int n;
int map[17][17];
int dp[17][17];
int dy[3] = {1, 0, 1};
int dx[3] = {1, 1, 0};

int sol(int c, int y, int x){
    if(y == n-1 && x == n-1) return dp[y][x] = 1;
    bool check[3] = {0, 0, 0};
    dp[y][x] = 0;
    for(int i=0;i<3;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<n && nx<n && map[ny][nx] != 1) check[i] = 1;
    }
    if(check[1] && c != 2) dp[y][x] += sol(1, y, x + 1);
    if(check[2] && c != 1) dp[y][x] += sol(2, y + 1, x);
    if(check[0] && check[1] && check[2]) dp[y][x] += sol(0, y + 1, x + 1);
    return dp[y][x];
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    sol(1, 0, 1);
    cout << dp[0][1];
    return 0;
}
