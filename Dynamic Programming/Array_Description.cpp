#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const int M = 1e9+7;

int main(){
    int n, m; cin>>n>>m;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)cin>>arr[i];
    vector<vector<ll>> dp(n, vector<ll> (m+2, 0));
    if(arr[0]==0)for(int i = 1; i <= m; i++)dp[0][i] =1;
    else dp[0][arr[0]] = 1;
    for(int i = 1; i < n; i++){
        if(arr[i]!=0){
            dp[i][arr[i]] = dp[i-1][arr[i]-1] + dp[i-1][arr[i]] + dp[i-1][arr[i]+1];
            dp[i][arr[i]] %= M;
        }
        else{
            for(int j= 1; j <= m; j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j+1] + dp[i-1][j-1];
                dp[i][j] %= M;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++){
        ans += dp[n-1][i];
        ans %= M;
    }
    cout<<ans;
    return 0;
}