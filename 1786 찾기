#include<iostream>
#include<vector>
#include<string>
using namespace std;

int ans;
vector<int> index;

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

void kmp(string a, string b){
    int n = a.length(), m = b.length(), j = 0;
    vector<int> table = make_table(b);
    for(int i=0;i<n;i++){
        while(j>0 && a[i] != b[j]){
            j = table[j-1];
        }
        if(a[i] == b[j]){
            if(j == m-1) {
                index.push_back(i - m + 2);
                ans++;
            }
            j++;
        }
    }
}

int main(void){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    kmp(a, b);
    cout << ans << '\n';
    for(int i=0;i<ans;i++){
        cout << index[i] << " ";
    } 
    return 0;
}
