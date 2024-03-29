#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 500001;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h;
    cin >> n >> h;
    vector<int> bot(n / 2), top(n / 2);

    for (int i = 0; i < n / 2; i++) {
        cin >> bot[i] >> top[i];
    }
    sort(bot.begin(), bot.end());
    sort(top.begin(), top.end());
    int result = INF;
    int c = 1;

    for (int i = 1; i <= h; i++){
        //해당 높이에 겹치는 석순
        int temp = bot.size() - (lower_bound(bot.begin(), bot.end(), i) - bot.begin());
        //해당 높이에 겹치는 종유석
        temp += top.size() - (upper_bound(top.begin(), top.end(), h - i) - top.begin());
        if (result == temp) c++;
        else if (result > temp){
            result = temp;
            c = 1;
        }
    }
    cout << result << " " << c;
    return 0;
}
