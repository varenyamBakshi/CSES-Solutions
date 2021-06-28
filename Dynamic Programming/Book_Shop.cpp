#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
    int n, x; cin>>n>>x;
    vector<ll> price(n), page(n);
    for(int i = 0; i < n; i++) cin>>price[i];
    for(int i = 0; i < n; i++) cin>>page[i];
    vector<ll> dp(x+1,0);
    for(int i = 0; i < n; i++){
        for(int j = x; j>0; j--){
            if(j<price[i])break;
            //if(dp[j-price[i]]==INT_MIN)continue;
            dp[j] = max(dp[j], dp[j-price[i]] + page[i]);
        }
        // for(auto it: dp)cout<<it<<" ";
        // cout<<endl;
    }
    cout<<dp[x];
    return 0;
}