#include<bits/stdc++.h>
using namespace std;

const int vsize = 1e5;
set<int> adj[vsize+1];
int deg[vsize+1];

int main(){ 
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b; cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
        ++deg[a]; ++deg[b];
    }
    int i;
    for(i = 1; i <= n; i++){
        if(deg[i]%2) break;
    }
    if(i<=n){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    stack<int> nodes;
    nodes.push(1);
    vector<int> ans;
    while(!nodes.empty()){
        int curr = nodes.top();
        if(deg[curr]==0){
            ans.push_back(curr);
            nodes.pop();
        }
        else{
            int next = *(adj[curr].begin());
            adj[next].erase(curr);
            adj[curr].erase(next);
            nodes.push(next);
            --deg[curr]; --deg[next];
        }
    }
    if(ans.size()==m+1)for(auto it: ans)cout<<it<<" ";
    else cout<<"IMPOSSIBLE";
    return 0;
}