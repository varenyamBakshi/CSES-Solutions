#include<bits/stdc++.h>
using namespace std;

const int vsize = 2e5;
vector<int> adj[vsize+1];
int subtree[vsize+1];
int n; 

void dfs(int node, int par){
    subtree[node] = 1;
    for(auto it: adj[node]){
        if(it==par)continue;
        dfs(it, node);
        subtree[node]+= subtree[it];
    }
}

int centroid(int node, int par){
    for(auto child: adj[node]){
        if(child!= par && subtree[child]> (n/2) ) return centroid(child, node);

    }
    return node;
}

int main(){
    cin>>n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    int ans = centroid(1,-1);
    cout<<ans;
    return 0;
}