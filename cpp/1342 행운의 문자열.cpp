#include<iostream>
using namespace std;

string a;
int al[26];
int ans;

void bt(int x, int cnt){
    if(cnt==a.length()){
        for(int i=0;i<26;i++){
            if(al[i]!=0 && i!=x) ans++;
        }
        return;
    }

    for(int j = 0;j<26;j++){
        if(al[j]!=0 && j!=x){
            al[j]--;
            bt(j,cnt+1);
            al[j]++;
        }
    }
    
}

int main(void){
    cin>>a;
    for(int i=0;i<a.length();i++){
        al[a[i]-'a']++;
    }
    bt(26, 1);
    cout<<ans;
    return 0;
}
