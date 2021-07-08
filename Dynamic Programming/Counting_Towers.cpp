#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const int M =1e9+7;
const int vsize = 1e6;

int main(){
    int t, n;
    cin>>t;
    vector<vector<ll>> dp(vsize+1, vector<ll>(2));// dp[i][0] box are disjoint dp[i][1] box are joined
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= vsize; i++){
        dp[i][0] = 4*dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0] + 2*dp[i-1][1];
        dp[i][0] %= M;
        dp[i][1] %= M;
    }
    while(t--){
        cin>>n;
        cout<<(dp[n][0] + dp[n][1])%M<<endl;
    }
    return 0;
}