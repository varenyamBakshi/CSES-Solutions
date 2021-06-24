#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const int M = 1e9+7;


int main(){
    ll n,x; cin>>n>>x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++)cin>>coins[i];
    vector<ll> dp(x+1,0);
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int num = 0; num< n; num++){
            if(coins[num]>i)continue;
            dp[i] += dp[i-coins[num] ];
            dp[i]%= M;
        }
    }
    cout<<dp[x]<<endl;
    
    return 0;
}
