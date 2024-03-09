#include<iostream>
#include<queue>
using namespace std;

int mul[101];
bool plug_in[101];
queue<int> input_order;
queue<int> next_index[101]; 

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i=0; i<k; i++){
        int a;
        cin >> a;
        input_order.push(a);
        next_index[a].push(i); 
    }
    int cnt = 0, ans = 0;
    while(!input_order.empty()){
        int now = input_order.front();
        input_order.pop();

        if(plug_in[now]) next_index[now].pop();
        else if(mul[n-1]==0){
            plug_in[now] = true;
            mul[cnt] = now;
            cnt++;
            next_index[now].pop();
        }
        else{
            int change = -1, change_index;
            for(int i=0;i<n;i++){
                if(next_index[mul[i]].empty()){
                    change = next_index[mul[i]].front();
                    change_index = i;
                    break;
                }
                else if(next_index[mul[i]].front() > change){
                    change = next_index[mul[i]].front();
                    change_index = i;
                }
            }
            plug_in[mul[change_index]] = false;
            plug_in[now] = true;
            mul[change_index] = now;
            next_index[now].pop();
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
