#include<iostream>
using namespace std;

int g, p, result;
int checkGate[100001];

int getParent(int x){
    if (checkGate[x] == x) return x;
    else return checkGate[x] = getParent(checkGate[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    
    checkGate[a] = b;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> g >> p;
    for (int i=1;i<=g;i++)
        checkGate[i] = i;
    for (int i=1;i<=p;i++){
        int gi, minGate;
        
        cin >> gi;
        minGate = getParent(gi);
        if (minGate == 0)
            break;
        else {
            unionParent(minGate, minGate - 1);
            result++;
        }
    }
    cout << result;
    return 0;
}
