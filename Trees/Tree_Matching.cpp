#include<bits/stdc++.h>
using namespace std;

const int vsize = 2e5;
vector<int> adj[vsize+1];
vector<vector<int>> dp(2, vector<int>(vsize+1,0));

void dfs(int node, int par){
    //if(dp[0][node]!=-1 && dp[1][node]!=-1) return;
    dp[0][node] = dp[1][node] = 0;
    for(auto child: adj[node]){
        if(child==par) continue;
        dfs(child, node);
        dp[0][node] += dp[1][child];
    }
    
    for(auto child: adj[node]){
        if(child==par) continue;
        dp[1][node] = max(dp[1][node], dp[0][node]-dp[1][child]+dp[0][child]+1);
    }
}

int main(){
    int n; cin>>n;
    for(int i = 0; i < n-1; i++){
        int x, y; 
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1);
    cout<<max(dp[0][1],dp[1][1])<<endl;
    return 0;
}