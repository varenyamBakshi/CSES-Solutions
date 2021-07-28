#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
const int vsize = 1e5;
vector<int> adj[vsize+1];
vector<int> vis(vsize+1,0);
vector<int> ans;
int start = -1;
 
bool dfs(int node){
    vis[node] = 1;
    for(auto child: adj[node]){
        if(vis[child]==2)continue;
        if(vis[child]==1 && start==-1){
            start = child;
            ans.push_back(start);
            ans.push_back(node);
            vis[node] = 2;
            return true;
        }
        if(vis[child]==0 && dfs(child)){
            ans.push_back(node);
            vis[node] = 2;
            if(node==start){
                start = -2;
                return false;
            }
            return true;
        }
    }
    vis[node] = 2;
    return false;
}
 
int main(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(vis[i]==0){
            dfs(i);
            if(ans.size()>0)break;
        }
    }
    if(ans.size()==0)cout<<"IMPOSSIBLE\n";
    else{
        cout<<ans.size()<<endl;
        reverse(ans.begin(), ans.end());
        for(auto it: ans) cout<<it<<" ";
    }
    return 0;
}