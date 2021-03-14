#include<iostream>
using namespace std;

int n;
char map[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool visit[101][101];

void sol(int x, int y){
    visit[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<n){
            if(!visit[nx][ny]&&map[x][y]==map[nx][ny]){
                sol(nx,ny);
            }
        }
    }
}

void sol1(int x, int y){
    visit[x][y] = false;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<n){
            if(map[x][y]=='B'){
                if(visit[nx][ny]&&map[x][y]==map[nx][ny]){
                    sol1(nx,ny);
                }
            }
            else{
                if(visit[nx][ny]&&map[nx][ny]!='B'){
                    sol1(nx,ny);
                }
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j]) {
                cnt++;
                sol(i,j);
            }
        }
    }
    int cnt1 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]) {
                cnt1++;
                sol1(i,j);
            }
        }
    }
    printf("%d %d",cnt,cnt1);
    return 0;
}
