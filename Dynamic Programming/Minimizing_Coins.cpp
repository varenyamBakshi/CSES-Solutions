#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
    int n, x; cin>>n>>x;
    vector<int> coins(n);
    vector<ll> dp(x+1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++)cin>>coins[i];
    for(int i = 0; i < n; i++){
        for(int j = 1; j<= x; j++){
            if(j<coins[i] || dp[j-coins[i]]==INT_MAX) continue;
            dp[j] = min(dp[j], dp[j-coins[i]]+1);
        }
    }
    if(dp[x]==INT_MAX)cout<<-1<<endl;
    else cout<<dp[x]<<endl;
    return 0;
}