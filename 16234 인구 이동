#include<iostream>
#include<queue>
#include<stdlib.h>
#include<cstring>
#include<vector>
using namespace std;

int n, l, r;
int map[51][51];
bool check[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void bfs(int y, int x){
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    q.push({y, x});
    int cnt = 0, sum = 0;
    check[y][x] = true;
    
    while(!q.empty()){
        int ny = q.front().first;
        int nx = q.front().second;
        cnt++;
        sum += map[ny][nx];
        v.push_back({ny, nx});
        q.pop();
        for(int i=0;i<4;i++){
            int newy = ny + dy[i];
            int newx = nx + dx[i];
            if(newy>=0 && newy<n && newx >=0 && newx<n){
                int dis = abs(map[newy][newx] - map[ny][nx]);
                if(!check[newy][newx] && dis>=l && dis<=r) {
                    check[newy][newx] = true;
                    q.push({newy, newx});
                }
            }
        }
    }
    int index = sum/cnt;
    for(int i=0;i<v.size();i++){
        map[v[i].first][v[i].second] = index;
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> n >> l >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    while(1){
        bool checkin = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!check[i][j]) bfs(i, j);
                else checkin = true;
            }
        }
        if(!checkin) {
            cout << ans;
            break;
        }
        memset(check, 0, sizeof(check));
        ans++;
    }
    return 0;
}
