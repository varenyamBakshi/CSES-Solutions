#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int vsize = 1e5;
vector<int> adj[vsize+1];
int vis[vsize+1];
vector<int> ans;
int start = -1;

bool dfs(int node, int par){
    vis[node] = 1;
    for(auto child: adj[node]){
        if(child==par)continue;
        if(vis[child] && start ==-1){
            start = child;
            ans.push_back(start);
            ans.push_back(node);
            return true;
        }
        if(!vis[child] && dfs(child, node)){
            ans.push_back(node);
            if(node==start){
                start = -2;
                return false;
            }
            return true;
        }
    }
    return false;
}

int main(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, -1);
            if(ans.size()>0)break;
        }
    }
    if(ans.size()==0) cout<<"IMPOSSIBLE\n";
    else{
        cout<<ans.size()<<endl;
        for(auto it: ans)cout<<it<<" ";
    }
    return 0;
}