#include<iostream>
#include<map>
using namespace std;

int arr[2001];
int check[2001][2001];

int sol(int le, int ri){
    int result;
    if (le>=ri) return result = 1;
    else if (arr[le]!=arr[ri]) return result = 0;
    else if (check[le][ri] == 1) return 1;
    else if (check[le][ri] == -1) return 0;
    else {
        result = sol(le+1,ri-1);
        if (result == 1) check[le][ri] = 1;
        else check[le][ri] = -1;
        return result;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        printf("%d\n", sol(a-1,b-1));
    }
    return 0;
}
