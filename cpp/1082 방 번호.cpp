#include<iostream>
#include<vector>
using namespace std;

int cost[10];
bool cost_check[10];
int n, mon, min_index, min_cost = 51;
vector<int> v;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> cost[i];
        if(min_cost >= cost[i]){
            min_cost = cost[i];
            min_index = i;
        }
    }
    cin >> mon;
    if(mon>=min_cost){
        if(min_index == 0){
            int second_index, second_min = 51;
            for(int i=1;i<n;i++){
                if(second_min > cost[i]){
                    second_min = cost[i];
                    second_index = i;
                }
            }
            if(mon<second_min){
                printf("0");
                return 0;
            }
            else{
                mon-=second_min;
                v.push_back(second_index);
            }
        }
        while(mon>=min_cost){
            mon-=min_cost;
            v.push_back(min_index);
        }
        for(int i=0;i<v.size();i++){
            bool check = false;
            for(int j=n-1;j>min_index;j--){
                if(cost[j]<=mon+cost[v[i]]){
                    check = true;
                    mon+=(cost[v[i]]-cost[j]);
                    v[i] = j;
                    break;
                }
            }
            if(!check) break;
        }
        for(int i=0;i<v.size();i++){
            printf("%d",v[i]);
        }
    }
    return 0;
}
