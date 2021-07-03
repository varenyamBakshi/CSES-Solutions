#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n>>q;
    vector<string> forest(n);
    for(int i = 0; i < n; i++) cin>>forest[i];
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (forest[i-1][j-1]=='*');
        }
    }

    while(q--){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        ll ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        cout<<ans<<endl;
    }
    return 0;
}