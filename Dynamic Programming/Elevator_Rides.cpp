#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
    int n, x;
    cin>>n>>x;
    vector<ll> wt(n);
    for(int i = 0; i < n; i++)cin>>wt[i];
    vector<vector<ll>> dp((1<<n), vector<ll>(2));
    dp[0][0] = 1;
    dp[0][1] = x;
    for(int mask = 1; mask<(1<<n); mask++){
        dp[mask][0] = INT_MAX;
        dp[mask][1] = -1;
        for(int i = 0; i <n; i++){
            int bit = (1<<i);
            if(mask&bit){
                if(dp[mask^bit][0] < dp[mask][0]){
                    if(wt[i]<=dp[mask^bit][1]){
                        dp[mask][0] = dp[mask^bit][0];
                        dp[mask][1] = dp[mask^bit][1] - wt[i];
                    }
                    else if(x-wt[i] > dp[mask][1]){
                        dp[mask][0] = dp[mask^bit][0] + 1;
                        dp[mask][1] = x- wt[i];
                    }
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][0]; 

    return 0;
}