#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const int M = 1e9+7;

int n, m;

void permute(int prev, int id, vector<int> &next, int curr){
    if(id==n){
        next.push_back(curr);
        return ;
    }
    if((1<<id) & prev) permute(prev, id+1, next, curr);
    else{
        prev = prev^(1<<id);
        curr = curr^(1<<id);
        permute(prev, id+1, next, curr);
        curr^=(1<<id);
        if(id<n-1 && !(prev&(1<<(id+1)))){
            prev^=(1<<(id+1));
            permute(prev, id+2, next, curr);
        }
    }
}

int main(){
    cin>>n>>m;
    if((n*m)%2){
        cout<<0;
        return 0;
    }
    vector<vector<ll>> dp(m+1, vector<ll>((1<<n),0));
    dp[0][0] = 1;
    for(int col = 0; col < m; col++){
        for(int profile = 0; profile<(1<<n); profile++){
            if(col==0 && profile>0)break;
            if(dp[col][profile]==0)continue;
            vector<int> next;
            permute(profile, 0, next, 0);
            for(auto it:next) {
                dp[col+1][it] += dp[col][profile];
                dp[col+1][it] %= M;
            }
        }
    }
    cout<<dp[m][0];
    return 0;
}