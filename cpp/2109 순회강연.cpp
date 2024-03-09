#include<iostream>
#include<queue>
using namespace std;

int n;
int checkDay[10001];
priority_queue<pair<int, int>> pq;

int main(void){
    int result;
    int maxDay;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    maxDay = 0;
    for (int i=0;i<n;i++){
        int p, d;
        cin >> p >> d;
        pq.push({p, d});
        if (maxDay < d)
            maxDay = d;
    }
    result = 0;
    while (!pq.empty()){
        int pay;
        int day;
        
        pay = pq.top().first;
        day = pq.top().second;
        pq.pop();
        for (int i=day;i>=1;i--){
            if (checkDay[i] == 0){
                checkDay[i] = pay;
                break;
            }
        }
    }
    for(int i=1;i<=maxDay;i++)
        result += checkDay[i];
    cout << result;
    return 0;
}
