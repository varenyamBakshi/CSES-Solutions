#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const int vsize = 2e5;
vector<int> par(vsize+1);
vector<int> dp(vsize+1), vis(vsize+1, 0);
int start = -1;

void dfs(int node, int d){
    vis[node] = 1;
    dp[node] = d;
    if(vis[par[node]]==0) {
        dfs(par[node], d+1);
        if(start==-1)  dp[node] = dp[par[node]]+1;
        else {
            dp[node] = dp[par[node]];
            if(node==start)start=-1;
        }
    }
    else if(vis[par[node]]==2) dp[node] = dp[par[node]]+1;
    else{
        dp[node] = d-dp[par[node]]+1;
        if(par[node]!=node) start = par[node];
        else start = -1;
    }
    vis[node]=2;

}

int main(){
    int n; cin>>n;
    for(int i = 1; i<= n; i++){
        cin>>par[i];
    }
    for(int i = 1; i<= n; i++){
        if(vis[i]==0) {
            start = -1;
            dfs(i, 0);
        }
    }
    for(int i  = 1;i <= n; i++)cout<<dp[i]<<" ";
    return 0;
}