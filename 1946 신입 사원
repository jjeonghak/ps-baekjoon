#include<iostream>
#include<queue>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    
    cin >> t;
    while (t--){
        int n;
        int rankCutline;
        int passApplicant;
        priority_queue<pair <int, int>> applicantRankInfo;
        
        cin >> n;
        for (int i=0;i<n;i++){
            int firstRank;
            int secondRank;
            
            cin >> firstRank >> secondRank;
            applicantRankInfo.push({-firstRank, secondRank});
        }
        rankCutline = n + 1;
        passApplicant = 0;
        while (!applicantRankInfo.empty()){
            int secondRank;
            secondRank = applicantRankInfo.top().second;
            applicantRankInfo.pop();
            if (secondRank < rankCutline){
                rankCutline = secondRank;
                passApplicant++;
            }
            if (rankCutline == 1)
                break;
        }
        cout << passApplicant << '\n';
    }
    return 0;
}
