#include<bits/stdc++.h>
using namespace std;

const int vsize = 1e5;
vector<int> adj[vsize+1];
const int M = 1e9+7;

int main(){

    int n, m; cin>>n>>m;
    vector<int> in(n+1, 0);
    for(int i = 0; i < m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }
    
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    queue<int> bag;
    for(int i = 1; i <= n; i++) if(in[i]==0)bag.push(i);
    while(!bag.empty()){
        int curr = bag.front();
        bag.pop();
        for(auto it: adj[curr]){
            dp[it]+= dp[curr];
            dp[it]%= M;
            in[it]--;
            if(in[it]==0)bag.push(it);
        }
    }
    //for(int i = 1; i <= n; i++)cout<<dp[i]<<" ";
    cout<<dp[n];
}