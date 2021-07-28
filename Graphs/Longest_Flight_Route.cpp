#include<bits/stdc++.h>
using namespace std;

const int vsize = 1e5;
vector<int> adj[vsize+1];
const int INF = INT_MAX/10;
int dist[vsize+1], par[vsize+1];


int main(){
    int n, m; cin>>n>>m;
    vector<int> dist(n+1, -1), in(n+1, 0), par(n+1, -1);
    for(int i = 0; i < m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }
    queue<int> node;
    dist[1] = 0;
    for(int i = 1; i <= n; i++) if(in[i]==0) node.push(i);
    while(!node.empty()){
        int curr = node.front();
        node.pop();
        //if(dist[curr] == -1)continue;
        for(auto it: adj[curr]){
            in[it]--;
            if(in[it]==0) node.push(it);
            if(dist[curr]==-1) continue;
            if(dist[curr]+1 > dist[it]){
                dist[it] = dist[curr]+1;
                par[it] = curr;
            }
        }
    }
    if(dist[n]==-1)cout<<"IMPOSSIBLE\n";
    else{
        cout<<dist[n]+1<<endl;
        int curr = n;
        vector<int> ans;
        while(curr!=-1){
            ans.push_back(curr);
            curr = par[curr];
        }
        reverse(ans.begin(), ans.end());
        for(auto it: ans) cout<<it<<" ";
    }
    return 0;
}