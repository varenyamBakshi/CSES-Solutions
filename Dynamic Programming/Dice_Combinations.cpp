#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const int M = 1e9+7;


int main(){
    ll n; cin>>n;
    vector<ll> dp(n+1,0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int num = 1; num<= 6; num++){
            if(num>i)break;
            dp[i] += dp[i-num];
            dp[i]%= M;
        }
    }
    cout<<dp[n]<<endl;
    
    return 0;
}
