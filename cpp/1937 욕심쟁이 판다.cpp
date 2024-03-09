#include<iostream>
#include<algorithm>
using namespace std;

int n;
int map[501][501];
int dp[501][501];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int bt(int x, int y){
    if(dp[x][y]!=0) return dp[x][y];
    dp[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<=n && ny>=0 && ny<=n){
            if(map[nx][ny] > map[x][y]) {
                int temp = bt(nx,ny) + 1;
                dp[x][y] = max(dp[x][y],temp);
            }
        }
    }
    return dp[x][y];
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
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = max(ans, bt(i,j));
        }
    }
    cout << ans;
    return 0;
}
