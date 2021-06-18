#include<bits/stdc++.h>
using namespace std;

const int vsize = 2e5;
vector<int> adj[vsize+1];
int dist[vsize+1];

void dfs(int node, int par){
    dist[node] = dist[par]+1;
    for(auto child: adj[node]){
        if(child==par)continue;
        dfs(child, node);
    }
}

int main(){
    int n; cin>>n;
    for(int i = 0 ;i < n-1; i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    fill(dist, dist+n+1, 0);
    dfs(1,0);
    int maxid = 1;
    for(int i = 1; i <= n; i++) if(dist[maxid]<dist[i]) maxid = i;
    fill(dist, dist+n+1, 0);
    dist[0]=-1;
    dfs(maxid, 0);
    cout<<(*max_element(dist, dist+n+1));
    return 0;
}