#include<iostream>
#include<vector>
#include<algorithm>
#define INF 987654321;
using namespace std;

int n, m, num2;
int ans = INF;
vector<pair<int, int>> v;
vector<pair<int, int>> v1;
vector<pair<int, int>> pick;

int sol(pair<int,int>a, pair<int,int>b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int cnt, int pick_cnt){
    if(pick_cnt==m){
        int sum = 0;
        for(int i=0;i<v.size();i++){
            int temp = INF;
            for(int j=0;j<pick.size();j++){
                int temp1 = sol(v[i],pick[j]);
                if (temp > temp1) temp = temp1;
            }
            sum+=temp;
        }
        if(ans>sum) ans = sum;
        return;
    }
    if(cnt==num2) return;
    pair<int,int> temp3 = v1.back();
    v1.pop_back();    
    
    pick.push_back(temp3);
    dfs(cnt+1, pick_cnt+1);
    pick.pop_back();
    dfs(cnt+1, pick_cnt);
    v1.push_back(temp3);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin >> a;
            if (a==1) v.push_back({i,j});
            else if(a==2) {
                v1.push_back({i,j});
                num2++;
            }
        }
    }
    dfs(0,0);
    cout<<ans;
}
