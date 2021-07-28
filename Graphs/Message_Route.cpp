#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int vsize = 1e5; 
vector<int> adj[vsize+1];
int dist[vsize+1];

int main(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dist, -1, sizeof(dist));
    queue<int> bfs;
    bfs.push(1);
    dist[1] = 0;
    while(!bfs.empty()){
        int curr = bfs.front();
        bfs.pop();
        for(auto child: adj[curr]){
            if(dist[child]==-1) {
                dist[child] = dist[curr]+1;
                bfs.push(child);
            }
        }
    }
    if(dist[n]==-1)cout<<"IMPOSSIBLE\n";
    else{
        cout<<dist[n]+1<<endl;
        vector<int> ans;
        ans.push_back(n);
        int path = dist[n];
        int curr = n;
        while(path){
            for(auto it: adj[curr]){
                if(dist[it]==path-1){
                    ans.push_back(it);
                    path--;
                    curr = it;
                    break;
                }
            }
        }
        for(int i = ans.size()-1; i>=0; i--)cout<<ans[i]<<" ";
    }
    return 0;
}