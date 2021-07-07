#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9+7;

ll xgcd(ll a, ll b, int &x, int &y){
    if(b==0){
        x= 1;
        y = 0;
        return a;
    }
    int x1, y1;
    ll g = xgcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

ll inverse(ll a){
    int x, y;
    xgcd(a, M, x, y);
    return (x+M)%M;
}

int main(){
    int n; cin>>n;
    int sum = n*(n+1)/2;
    if(sum%2){
        cout<<0;
        return 0;
    }
    int target = sum/2;
    vector<ll> dp(target+1,0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = target; j>=i; j--) {
            dp[j] += dp[j-i];
            dp[j] %= M;
        }
    }
    ll ans = dp[target] * inverse(2) % M;
    cout<<ans;
    return 0;
}