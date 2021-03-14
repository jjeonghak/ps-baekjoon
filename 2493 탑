#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> v;
stack<pair<int, int>> s;
int ans[500001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    s.push({v[n-1],n-1});
    for(int i=n-2;i>=0;i--){
        if(!s.empty()) {
            while(s.top().first<=v[i]){
                ans[s.top().second] = i + 1;
                s.pop();
                if (s.empty()) break;
            }
        }
        s.push({v[i],i});
    }
    for(int i=0;i<n;i++){
        printf("%d",ans[i]);
        if (i!=n-1) printf(" ");
    }
    return 0;
}
