#include<iostream>
#include<algorithm>
using namespace std;

int map[1001][1001];
int dp[1001][1001];
int dy[3] = {0, 1, 1};
int dx[3] = {1, 1, 0};
int n, m;

int sol(int y, int x){
    if(dp[y][x] != -1) return dp[y][x];
    else if(y == n - 1 || x == m - 1) return dp[y][x] = map[y][x];
    int temp = 987654321;
    for(int i=0;i<3;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny>=0 && ny<n && nx>=0 && nx<m){
            if(map[ny][nx] != 0) temp = min(temp, sol(ny, nx));
            else{
                temp = 0;
                break;
            }
        }
    }
    return dp[y][x] = temp + 1;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            cin >> a;
            map[i][j] = a - '0';
            dp[i][j] = -1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == 1){
                int temp = sol(i, j);
                if(ans < temp) ans = temp;
            }
        }
    }
    
    cout << ans*ans;
    return 0;
}
