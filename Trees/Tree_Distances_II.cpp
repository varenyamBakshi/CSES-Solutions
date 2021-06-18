#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int n;

const int vsize = 2e5;
ll subtree[vsize+1], sub[vsize+1], dp[vsize+1];
vector<int> adj[vsize+1];

void dfs1(int node, int par){
    subtree[node] = 1;
    sub[node] = 0;
    for(auto child: adj[node]){
        if(child == par)continue;
        dfs1(child, node);
        sub[node] += sub[child] + subtree[child];
        subtree[node] += subtree[child];
    }
}

void dfs2(int node, int par){
    
    for(auto child: adj[node]){
        if(child == par)continue;
        dp[child] = dp[node] - (subtree[child]) + (n - subtree[child]);
        dfs2(child, node);
    }
}

int main(){
    cin>>n;
    for(int i = 0; i < n-1; i++){
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(1,-1);

    dp[1] = sub[1];
    dfs2(1,-1);
    for(int i = 1; i <= n; i++) cout<<dp[i]<<" ";
    cout<<endl;
    return 0;
}