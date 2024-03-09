#include<iostream>
using namespace std;

int dp[1001], arr[1001];
int n;

int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
	    int min = 0;
	    for (int j = 0; j < i; j++) {
		    if (arr[i] < arr[j]) { 
		    	if (min < dp[j]) min = dp[j];
	    	}
    	}
	    dp[i] = min + 1;
	    if (max < dp[i]) max = dp[i];
    }
    cout<<max;
    return 0;
}
