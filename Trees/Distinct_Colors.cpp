#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define ff first
#define ss second

const int vsize = 2e5+5;
int col[vsize+1], cnt[vsize+1];
set<int> *color[vsize+1];
vector<int> adj[vsize+1];

void dfs(int node, int par){
    int maxchild = 0;
    //color[node] = new set<int>;
    for(auto child: adj[node]){
        if(child==par)continue;
        dfs(child, node);
        if(color[child]->size()> color[maxchild]->size()){
            maxchild = child;
        }
    }
    if(maxchild==0) color[node] = new set<int>;
    else color[node] = color[maxchild];
    for(auto child: adj[node]){
        if(child==par || child == maxchild) continue;
        for(auto it: *color[child]) color[node]->insert(it);
        color[child] = nullptr;
    }
    color[node]->insert(col[node]);
    cnt[node] = color[node]->size();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    
    for(int i = 1; i <= n; i++)cin>>col[i];
    for(int i = 0; i < n-1; i++){
        int x, y; 
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    color[0] = new set<int>;
    dfs(1,-1);
    for(int i = 1; i <= n; i++) cout<<cnt[i]<<" ";
    return 0;
}