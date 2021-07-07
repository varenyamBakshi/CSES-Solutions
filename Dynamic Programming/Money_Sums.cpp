#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;
    vector<int> x(n);
    int sum = 0;
    for(auto &it: x) {
        cin>>it;
        sum += it;
    }
    vector<bool> dp(sum+1, false);
    dp[0] = true;

    for(int i = 0; i < n; i++){
        for(int j = sum ; j>=x[i]; j--) dp[j] = dp[j] || dp[j-x[i]];
    }
    int cnt = 0;
    for(int i = 1; i<= sum; i++) if(dp[i])cnt++;
    cout<<cnt<<endl;
    for(int i = 1; i<= sum; i++)if(dp[i]) cout<<i<<" ";
    return 0;
}