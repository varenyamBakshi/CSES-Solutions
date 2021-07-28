#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int vsize = 1e9;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin>>n>>q;
    int maxn = log2(vsize)+1;
    vector<vector<int>> par(n+1, vector<int> (maxn+1, 0));
    for(int i = 1; i <= n; i++) cin>>par[i][0];
    for(int i = 1;i <= maxn; i++){
        for(int j = 1; j <= n; j++){
            int p = par[j][i-1];
            par[j][i] = par[p][i-1];
        }
    }
    while(q--){
        int x, k; cin>>x>>k;
        for(int i = maxn; i>=0; i--){
            if(k<(1ll<<i))continue;
            k-=(1ll<<i);
            if(par[x][i]==x)break;
            x = par[x][i];
        }
        cout<<x<<endl;
    }

    return 0;
}