#include<bits/stdc++.h>
using namespace std;

const int vsize = 1e5;
vector<int> adj[vsize+1];
int in[vsize+1];

int main(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }
    queue<int> ord;
    for(int i = 1; i <= n; i++) if(in[i]==0)ord.push(i);
    vector<int> ans;
    while(!ord.empty()){
        int curr = ord.front();
        ord.pop();
        ans.push_back(curr);
        for(auto it: adj[curr]){
            in[it]--;
            if(in[it]==0)ord.push(it);
        }
    }
    if(ans.size()<n)cout<<"IMPOSSIBLE\n";
    else{
        for(auto it: ans) cout<<it<<" ";
    }
    return 0;
}