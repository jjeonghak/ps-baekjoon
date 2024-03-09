#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

priority_queue<int> pq;
vector<pair<int, int>>v;

bool compare(pair<int, int>a, pair<int, int> b){
    if(a.first > b.first) return true;
    else return false;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, p;
    bool check = true;
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    cin >> l >> p;
    v.push_back({l, 0});
    sort(v.begin(), v.end(), compare);
    int cnt = 0;
    while(!v.empty()){
        int now = v.back().first;
        int nowp = v.back().second;
        v.pop_back();
        while(p < now){
            if(!pq.empty()){
                p += pq.top();
                pq.pop();
                cnt++;
            }
            else {
                check = false;
                break;
            }
        }
        if(!check) break;
        pq.push(nowp);
    }
    if(check) cout << cnt;
    else cout << "-1";
    return 0;
}
