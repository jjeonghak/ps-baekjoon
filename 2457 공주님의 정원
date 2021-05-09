#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>> v;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first<b.first) return true;
    else return false;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({a*100 + b, c*100 + d});
    }
    sort(v.begin(),v.end(),compare);
    int index = -1, temp = 0, ans = 0;
    for(int i=301;i<=1130&&index<n;i=temp){
        bool check = false;
        index++;
        for(int j=index;j<v.size();j++){
            if(v[j].first>i) break;
            if(temp<v[j].second){
                temp = v[j].second;
                index = j;
                check  = true;
            }
        }
        if(check) ans++;
        else {
            cout << 0;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
