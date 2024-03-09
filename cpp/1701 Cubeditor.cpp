#include<iostream>
#include<vector>
using namespace std;

vector<int> make_table(string a){
    vector<int> ret(a.length(), 0);
    int j = 0;
    for(int i=1;i<a.length();i++){
        while(j>0 && a[i] != a[j]){
            j = ret[j-1];
        }
        if(a[i] == a[j]) ret[i] = ++j;
    }
    return ret;
}

main(void){
    string a;
    int ans = 0;
    cin >> a;
    while(!a.empty()){
        vector<int> v = make_table(a);
        for(int i=0;i<v.size();i++){
            if(v[i]>ans) ans = v[i];
        }
        a.erase(0,1);
    }
    cout << ans;
}
