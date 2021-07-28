#include<bits/stdc++.h>
using namespace std;


const int vsize = 1e5;
vector<int> adj[vsize+1];
int team[vsize+1];

bool dfs(int node, int t){
    team[node] = t;
    for(int child: adj[node]){
        if(team[child] == t) return false;
        if(team[child]== -1 && !dfs(child, t^1)) return false;
    }
    return true;
}

int main(){
    int n, m; cin>>n>>m;
    for(int i = 0; i< m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(team, -1, sizeof(team));
    for(int i = 1; i <=n; i++){
        if(team[i]==-1){
            if(!dfs(i, 0)){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for(int i = 1; i <= n; i++)cout<<team[i]+1<<" ";
    return 0;
}