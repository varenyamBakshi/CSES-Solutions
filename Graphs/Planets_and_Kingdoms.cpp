#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int vsize = 1e5;
vector<int> adj[vsize+1], revadj[vsize+1];
int vis[vsize+1], kingdom[vsize+1], grp;
vector<int> order;

void dfs1(int node){
    vis[node] = 1;
    for(auto child: adj[node]){
        if(!vis[child])dfs1(child);
    }
    order.push_back(node);
}

void dfs2(int node){
    vis[node] = 0;
    kingdom[node] = grp;
    for(auto child: revadj[node]){
        if(vis[child]==1)dfs2(child);
    }
}

int main(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        revadj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) if(!vis[i])dfs1(i);
    grp = 0;
    for(int i = order.size()-1; i>=0 ; i--){
        if(vis[order[i]]==1){
            grp++;
            dfs2(order[i]);
            
        }
    }
    cout<<grp<<endl;
    for(int i = 1; i <= n; i++) cout<<kingdom[i]<< " ";
    return 0;
}