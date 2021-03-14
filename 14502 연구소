#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n, m, k, cnt1, ans;
int map[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool visit[101][101];
bool c[101][101];

void sol(int x, int y){
    visit[x][y] = true;
    cnt1--;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<m){
            if(!visit[nx][ny]&&map[nx][ny]!=1){
                sol(nx,ny);
            }
        }
    }
}

void bt(int cnt){
    if (cnt==3){
        cnt1 = m*n - k;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visit[i][j]&&map[i][j]==2) {
                    sol(i,j);
                }
            }
        }
        if(cnt1>ans) ans = cnt1;
        memset(visit, false, sizeof(visit));
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!c[i][j]&&map[i][j]==0){
                c[i][j] = true;
                map[i][j] = 1;
                bt(cnt + 1);
                c[i][j] = false;
                map[i][j] = 0;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]==1) k++;
        }
    }
    k+=3;
    bt(0);
    printf("%d", ans);
    return 0;
}
