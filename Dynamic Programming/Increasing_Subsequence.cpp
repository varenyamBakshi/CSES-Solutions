#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n; cin>>n;
    vector<ll> x(n);
    for(int i = 0; i< n; i++)cin>>x[i];
    vector<ll> dp;
    dp.push_back(x[0]);
    for(int i = 1; i < n; i++){
        int num = lower_bound(dp.begin(), dp.end(), x[i]) - dp.begin();
        if(num==dp.size()) {
            dp.push_back(x[i]);
        }
        else dp[num] = x[i];
    }
    cout<<dp.size();
    return 0;
}