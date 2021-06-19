#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int vsize = 2e5+5;
vector<int> adj[vsize+1];

void dfs(int x, vector<vector<int>> &par){
    for(auto child: adj[x]){
        par[child][0] = x;
        dfs(child, par);
    }
}

int main(){
    int n, q; cin>>n>>q;
    for(int i = 2; i <=n; i++){
        int x; cin>>x;
        adj[x].push_back(i);
    }
    int maxn = log2(n)+1;
    vector<vector<int>> par(n+1, vector<int>(maxn+1,-1));
    dfs(1, par);

    for(int i = 1; i <= maxn; i++){
        int cnt = 0;
        for(int curr = 1; curr<= n; curr++){
            int pre = par[curr][i-1];
            if(pre==-1)continue;
            par[curr][i] = par[pre][i-1];
            if(par[curr][i]!=-1)cnt++;
        }
        if(cnt == 0) break;
    }
    while(q--){
        int child, level;
        cin>>child>>level;
        for(int i = maxn; i>=0; i--){
            if((1ll<<i)<=level){
                child = par[child][i];
                level -= (1ll<<i);
            }
            if(level==0||child==-1)break;
        }
        cout<<child<<endl;
    }
    return 0;
}