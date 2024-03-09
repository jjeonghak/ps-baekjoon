#include<iostream>
using namespace std;

int n;
int arr[101];
long long dp[101][21];  //인덱스, 총합의 크기 별로 나오는 등식의 갯수 저장

long long sol(){
    dp[0][arr[0]] = 1;
    
    for(int i=1;i<n-1;i++){  //i는 인덱스 
        for(int j=0;j<21;j++){  //j는 총합의 크기
            if(dp[i-1][j] != 0){
                if(j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i - 1][j];
                if(j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];
            }
        }
    }
    
    return dp[n - 2][arr[n - 1]];
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    cout << sol();
    return 0;
}
