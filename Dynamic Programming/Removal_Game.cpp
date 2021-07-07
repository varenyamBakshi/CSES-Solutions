#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
    int n; cin>>n;
    vector<ll> x(n);
    for(int i = 0; i < n; i++)cin>>x[i];
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for(int i = n-1; i>=0; i--){
        for(int j = i; j<n; j++){
            if(i==j)dp[i][j] = x[i];
            else{
                dp[i][j] = max(x[i] - dp[i+1][j], x[j]-dp[i][j-1]);
            }
        }
    }
    ll sum = 0;
    for(int i = 0; i < n; i++)sum += x[i];
    ll ans = (sum+dp[0][n-1])/2;
    cout<<ans<<endl;
    return 0;
}