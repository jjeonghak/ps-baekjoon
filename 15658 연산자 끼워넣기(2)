#include<iostream>
#include<vector>
#define INF 2000000000
using namespace std;

int arr[12];
int arr1[4];
int n, ans1=-INF, ans2=INF;

void bt(int cnt, int sum){
    if(cnt==n){
        if(ans1<sum) ans1 = sum;
        if(ans2>sum) ans2 = sum;
        return;
    }
    if(arr1[0]!=0){
        arr1[0]--;
        bt(cnt+1, sum+arr[cnt]);
        arr1[0]++;
    }
    if(arr1[1]!=0){
        arr1[1]--;
        bt(cnt+1, sum-arr[cnt]);
        arr1[1]++;
    }
    if(arr1[2]!=0){
        arr1[2]--;
        bt(cnt+1, sum*arr[cnt]);
        arr1[2]++;
    }
    if(arr1[3]!=0){
        arr1[3]--;
        bt(cnt+1, sum/arr[cnt]);
        arr1[3]++;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<4;i++){
        cin >> arr1[i];
    }
    bt(1,arr[0]);
    cout<<ans1<<"\n"<<ans2;
}
