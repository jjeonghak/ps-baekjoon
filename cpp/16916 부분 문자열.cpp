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
    return  ret;
}

int kmp(string a, string b){
    int n = a.length(), m = b.length(), j = 0;
    vector<int> table = make_table(b);
    for(int i=0;i<n;i++){
        while(j>0 && a[i] != b[j]){
            j = table[j-1];
        }
        if(a[i] == b[j]){
            if(j == m-1) return 1;
            j++;
        }
    }
    return 0;
}

int main(void){
    string a, b;
    cin >> a >> b;
    cout << kmp(a, b);
    return 0;
}
