#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define ff first
#define ss second

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q; cin>>n>>q;

    int maxn = log2(n)+1;
    vector<vector<ll>> stable(n, vector<ll>(maxn));
    for(int i = 0; i <n; i++) cin>>stable[i][0];
    
    for(int len = 1; len < maxn; len++){
        for(int curr = 0; curr+(1<<len) <= n; curr++){
            stable[curr][len] = min(stable[curr][len-1], stable[curr+(1<<(len-1))][len-1]);
        }
    }
    
    while(q--){
        int x,y;
        cin>>x>>y;
        int l = y-x+1;
        x--;y--;
        l = log2(l);
        ll ans = min(stable[x][l], stable[y-(1<<l)+1][l]);
        cout<<ans<<endl;
    }
    

    return 0;
}