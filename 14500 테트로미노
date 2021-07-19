#include<iostream>
using namespace std;

int n, m, ans;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int map[501][501];
bool check[501][501];

void dfs(int cnt, int sum , int x, int y){
    if(cnt == 3){
        if(ans < sum) ans = sum;
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!check[nx][ny] && nx>=0 && nx<n && ny>=0 && ny<m){
            check[nx][ny] = true;
            dfs(cnt + 1, sum + map[nx][ny], nx, ny);
            check[nx][ny] = false;
        }
    }
}

void case5(int x, int y){  //dfs로 탐색불가, 따로 고려
    for(int i=0;i<4;i++){
        int sum = map[x][y];
        for(int j=0;j<4;j++){
            if(i == j) continue;
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx<0 || nx>n || ny<0 || ny>m) break;
            else sum += map[nx][ny];
        }
        if(ans<sum) ans = sum;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            check[i][j] = true;
            dfs(0, map[i][j], i, j);
            case5(i, j);
            check[i][j] = false;
        }
    }
    cout << ans;
    return 0;
}
