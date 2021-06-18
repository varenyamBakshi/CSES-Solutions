#include<bits/stdc++.h>
using namespace std;

const int vsize = 2e5;
vector<int> adj[vsize+1];


void dfs(int node, int par, vector<int> &dist){
    for(auto child: adj[node]){
        if(child==par)continue;
        dist[child] = dist[node]+1;
        dfs(child, node, dist);
    }
}


int main(){
    int n; cin>>n;
    for(int i = 0; i < n-1; i++){
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> dist1(n+1,0), dist2(n+1,0);
    dfs(1,-1, dist1); // dfs from root node

    int end1 = 0;
    for(int i = 1; i <= n; i++) if(dist1[i]>dist1[end1]) end1 = i;  //finding one endpoint
    fill(dist1.begin(), dist1.end(), 0);
    dfs(end1, -1, dist1);
    
    int end2 = 0;
    for(int i = 1; i <= n; i++) if(dist1[i]>dist1[end2]) end2 = i;  //finding other endpoint
    dfs(end2,-1, dist2);
    for(int i = 1; i <= n; i++){
        cout<<max(dist1[i], dist2[i])<<" ";
    }
    cout<<"\n";
    return 0;
}