#include<iostream>
using namespace std;

int n, m, ans = -1;
int map[11][11];
pair<int, int> hole;
bool finish, holeInB;

pair<pair<int,int>, pair<int,int>> dx(char oper, const pair<int, int> r, const pair<int, int> b){ //x direction movement
    bool checkR = false, checkB = false;
    int distanceR = 0, distanceB = 0;
    pair<int, int> nr = r;
    pair<int, int> nb = b;
    
    for(int i = 0; i < m; i++){
        if(checkR && checkB) break;
        
        if(!checkR)  {
            if(oper == '+') nr.second += 1;
            else nr.second -= 1;
            if(map[nr.first][nr.second] == 1){
                if(oper == '+') nr.second -= 1;
                else nr.second += 1;
                checkR = true;
            }
            else distanceR++;
        }

        if(!checkB)  {
            if(oper == '+') nb.second += 1;
            else nb.second -= 1;
            if(map[nb.first][nb.second] == 1){
                if(oper == '+') nb.second -= 1;
                else nb.second += 1;
                checkB = true;
            }
            else distanceB++;
        }
        
        if(hole.first == nb.first && hole.second == nb.second) {
            finish = false;
            holeInB = true;
            return {nr, nb};
        }
        if(hole.first == nr.first && hole.second == nr.second) {
            finish = true;
            checkR = true;
        }
    }
    if(nr == nb){
        if(oper == '+') distanceR > distanceB ? (nr.second -= 1) : (nb.second -= 1);
        else distanceR > distanceB ? (nr.second += 1) : (nb.second += 1);
    }
    return {nr, nb};
}

pair<pair<int,int>, pair<int,int>> dy(char oper, const pair<int, int> r, const pair<int, int> b){ //y direction movement
    bool checkR = false, checkB = false;
    int distanceR = 0, distanceB = 0;
    pair<int, int> nr = r;
    pair<int, int> nb = b;
    
    for(int i = 0; i < n; i++){
        if(checkR && checkB) break;
        
        if(!checkR)  {
            if(oper == '+') nr.first += 1;
            else nr.first -= 1;
            if(map[nr.first][nr.second] == 1){
                if(oper == '+') nr.first -= 1;
                else nr.first += 1;
                checkR = true;
            }
            else distanceR++;
        }
        
        if(!checkB)  {
            if(oper == '+') nb.first += 1;
            else nb.first -= 1;
            if(map[nb.first][nb.second] == 1){
                if(oper == '+') nb.first -= 1;
                else nb.first += 1;
                checkB = true;
            }
            else distanceB++;
        }
        
        if(hole.first == nb.first && hole.second == nb.second) {
            finish = false;
            holeInB = true;
            return {nr, nb};
        }
        if(hole.first == nr.first && hole.second == nr.second) {
            finish = true;
            checkR = true;
        }
    }
    if(nr == nb){
        if(oper == '+') distanceR > distanceB ? (nr.first -= 1) : (nb.first -= 1);
        else distanceR > distanceB ? (nr.first += 1) : (nb.first += 1);
    }
    return {nr, nb};
}

void dfs(int cnt, int dir,const pair<int, int> r,const pair<int, int> b){
    if(cnt == 11) return;
    for(int i=0;i<2;i++){
        pair<int, int> nr = r;
        pair<int, int> nb = b;
        char  oper;
        pair<pair<int,int>, pair<int,int>> nxny;
        switch(dir){
            case 1:
                if(i == 0) oper = '+';
                else oper = '-';
                nxny = dx(oper, nr, nb);
                break;
                
            case 2:
                if(i == 0) oper = '+';
                else oper = '-';
                nxny = dy(oper, nr, nb);
                break;
        }
        
        if(holeInB) holeInB = false;
        else{
            nr = nxny.first;
            nb = nxny.second;
            if(finish) {
                if(ans == -1 || ans > cnt )ans = cnt;
                finish = false;
                return;
            }
            else if(dir == 1) dfs(cnt+1, 2, nr, nb);
            else if(dir == 2) dfs(cnt+1, 1, nr, nb);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pair<int, int> r, b;
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            cin >> a;
            if(a == '#') map[i][j] = 1;
            else if(a == 'O') hole = {i, j};
            else if(a == 'B') b = {i, j};
            else if(a == 'R') r = {i, j};
        }
    }
    dfs(1, 1, r, b);
    dfs(1, 2, r, b);
    cout << ans;
    return 0;
}
