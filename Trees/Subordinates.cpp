#include<bits/stdc++.h>
using namespace std;

const int vsize = 2e5;
vector<int> adj[vsize+1];
int subtree[vsize+1];

void dfs(int x){
    subtree[x] = 0;
    for(auto child: adj[x]){
        dfs(child);
        subtree[x] += 1+subtree[child];
    }
}

int main(){
    int n; cin>>n;
    for(int i = 2; i <= n; i++) {
        int x; cin>>x;
        adj[x].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) cout<<subtree[i]<<" ";
    return 0;
}