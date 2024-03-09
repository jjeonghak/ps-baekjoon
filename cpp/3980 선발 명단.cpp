#include<iostream>
using namespace std;

int map[11][11];
bool position[11];
int ans;

void bt(int sum, int cnt){
    if (cnt==11){
        if(sum>ans) ans = sum;
        return;
    }
    for(int i=0;i<11;i++){
        if(map[cnt][i]!=0&&!position[i]){
            sum += map[cnt][i];
            position[i] = true;
            bt(sum, cnt+1);
            sum -= map[cnt][i];
            position[i] = false;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin>>c;
    while(c--){
        for(int i=0;i<11;i++){
            for(int j=0;j<11;j++){
                cin>>map[i][j];
            }
        }
        ans = 0;
        bt(0,0);
        printf("%d\n", ans);
    }
    return 0;
}
