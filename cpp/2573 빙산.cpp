#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
int map[301][301];
bool check[301][301];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int y, int x){
    queue<pair<int, int>> q;
    vector<pair<pair<int, int>, int>> v;
    q.push({y, x});
    check[y][x] = true;
    while(!q.empty()){
        int ny = q.front().first;
        int nx = q.front().second;
        int cnt = 0;
        q.pop();
        
        for(int i=0;i<4;i++){
            int newy = ny + dy[i];
            int newx = nx + dx[i];
            if(!check[newy][newx] && newy>=0 && newy<n && newx>=0 && newx<m){
                if(map[newy][newx] == 0) cnt++;
                else {
                    check[newy][newx] = true;
                    q.push({newy, newx});
                }
            }
        }
        v.push_back({{ny, nx}, cnt});
    }
    
    for(int i=0;i<v.size();i++){
        map[v[i].first.first][v[i].first.second] -= v[i].second;
        if(map[v[i].first.first][v[i].first.second] < 0) map[v[i].first.first][v[i].first.second] = 0;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    while(1){
        bool checkin = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!check[i][j] && map[i][j] != 0){
                    if (!checkin) {
                        bfs(i, j);
                        checkin = true;
                    }
                    else {
                        cout << ans;
                        return 0;
                    }
                }
            }
        }
        if(!checkin) {
            cout << 0;
            return 0;
        }
        ans++;
        memset(check, 0, sizeof(check));
    }
}
