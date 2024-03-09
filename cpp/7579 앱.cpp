#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[101];
int c[101];
int dp[101][10001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sum = 0;

    cin >> n >> m;
    for(int i=0;i<2;i++){
        for(int j=1;j<=n;j++){
            if(i==0) cin >> arr[j];
            else {
                cin >> c[j];
                sum += c[j];
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j - c[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + arr[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    for(int i=0;i<=sum;i++){
        if(dp[n][i] >= m){
            cout << i;
            break;
        }
    }
    
    return 0;
}
