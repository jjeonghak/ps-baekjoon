#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

priority_queue<int> pq, pq1;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        pq.push(a);
    }
    int distance = pq.top(), ans = pq.top();
    pq.pop();

    while(!pq.empty()){
        pq1.push(distance - pq.top());
        distance = pq.top();
        pq.pop();
    }
    ans-=distance;
    for(int i=0;i<k-1;i++){
        if(pq1.empty()) break;
        ans-=pq1.top();
        pq1.pop();
    }
    cout << ans;
    return 0;
}
