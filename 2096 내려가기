#include<iostream>
#include<algorithm>
#define INF 210000000
using namespace std;

int n;
int map[3][2];
int dp_max[3][2];
int dp_min[3][2];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    cin >> n;
    for(int i=0;i<3;i++){
        cin >> map[i][cnt];
        dp_max[i][cnt] = map[i][cnt];
        dp_min[i][cnt] = map[i][cnt];
    }
    while(cnt++ != n - 1){
        int index = cnt % 2;
        cin >> map[0][index] >> map[1][index] >> map[2][index];
        for(int i=0;i<3;i++) dp_min[i][index] = INF;
        for(int i=0;i<3;i+=2){
            dp_max[i][index] = max(dp_max[i][index], 
                map[i][index] + dp_max[i][!index]);
            dp_min[i][index] = min(dp_min[i][index], 
                map[i][index] + dp_min[i][!index]);
            dp_max[i][index] = max(dp_max[i][index], 
                map[i][index] + dp_max[1][!index]);
            dp_min[i][index] = min(dp_min[i][index], 
                map[i][index] + dp_min[1][!index]);
        }
        for(int i=0;i<3;i++){
            dp_max[1][index] = max(dp_max[1][index], 
                map[1][index] + dp_max[i][!index]);
            dp_min[1][index] = min(dp_min[1][index], 
                map[1][index] + dp_min[i][!index]);
        }
    }
    int ans_max = -1, ans_min = INF;
    for(int i=0;i<3;i++){
        ans_max = max(ans_max, dp_max[i][!(cnt%2)]);
        ans_min = min(ans_min, dp_min[i][!(cnt%2)]);
    }
    cout << ans_max << ' ' << ans_min;
    return 0;
}
