#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
#define ll long long
#define endl "\n"

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++)cin>>grid[i];
    if(grid[0][0]=='*'){
        cout<<0;
        return 0;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i-1][j-1]=='*')continue;
            dp[i][j]+= dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= M;
        }
    }
    cout<<dp[n][n];
    return 0;
}