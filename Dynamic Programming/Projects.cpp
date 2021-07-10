#include<bits/stdc++.h>
using namespace std;

#define ll long long
bool comp(vector<ll> a, vector<ll> b){
    if(a[1] < b[1]) return true;
    if(a[1]==b[1]) return a[0]<=b[0];
    return false;
}

bool comp2(vector<ll> a, ll val){
    return a[1] < val;
}

int main(){
    int n; cin>>n;
    vector<vector<ll>> proj(n, vector<ll> (3));
    for(int i = 0; i< n; i++)cin>>proj[i][0]>>proj[i][1]>>proj[i][2];
    sort(proj.begin(), proj.end(), comp);

    vector<ll> dp(n);
    dp[0] = proj[0][2];
    for(int i = 1; i < n; i++){
        int id = lower_bound(proj.begin(), proj.begin()+i, proj[i][0], comp2) - proj.begin();
        if(id==0) dp[i] = proj[i][2];
        else dp[i] = dp[id-1] + proj[i][2];
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout<<dp[n-1];
    return 0;
}