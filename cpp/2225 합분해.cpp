#include<iostream>
#define MOD 1000000000
using namespace std;

int n,k;
int dp[201][201]; //k,n의 조합

int main(void){
    cin>>n>>k;
    for(int i=0;i<=n;i++) dp[1][i] = 1;
    for(int i=0;i<=k;i++) dp[i][0] = 1;
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++) dp[i][j] = (dp[i][j-1]+dp[i-1][j])%MOD;
    }
    printf("%d\n",dp[k][n]);
    return 0;
}
