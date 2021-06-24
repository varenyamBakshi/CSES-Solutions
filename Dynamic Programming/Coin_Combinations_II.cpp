#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
#define ll long long
#define endl "\n"

int main(){
    int n, x; cin>>n>>x;
    vector<ll> coins(n);
    for(int i = 0; i < n; i++)cin>>coins[i];
    vector<ll> dp(x+1);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = coins[i]; j <= x; j++){
            dp[j] += dp[j-coins[i]];
            dp[j] %= M;
        }
    }
    cout<<dp[x];
    return 0;
}