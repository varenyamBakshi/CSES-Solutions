#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int vsize = 1e5;
vector<int> adj[vsize+1];
int vis[vsize+1] = {0};

void dfs(int node){
    vis[node] = 1;
    for(auto child: adj[node]){
        if(!vis[child]) dfs(child);
    }
}

int main(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m ;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> nodes;
    for(int i= 1; i <= n; i++){
        if(vis[i]==0){
            nodes.push_back(i);
            dfs(i);
        }
    }
    cout<<nodes.size()-1<<endl;
    for(int i = 0; i< nodes.size()-1; i++){
        cout<<nodes[i]<<" "<<nodes[i+1]<<endl;
    }
    return 0;
}