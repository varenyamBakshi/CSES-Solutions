#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int vsize = 2e5+5;
vector<int> adj[vsize+1];
int d[vsize+1], dp[vsize+1] = {0};

void dfs(int x, int prev, vector<vector<int>> &par){
    for(auto child: adj[x]){
        if(child==prev) continue;
        par[child][0] = x;
        d[child] = d[x] + 1;
        dfs(child, x, par);
    }
}

void dfs1(int node, int par){
    for(auto child: adj[node]){
        if(child==par)continue;
        dfs1(child, node);
        dp[node]+=dp[child];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    for(int i = 2; i <=n; i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int maxn = log2(n)+1;
    vector<vector<int>> par(n+1, vector<int>(maxn+1,0));
    d[1] = 0;
    dfs(1, -1, par);

    for(int i = 1; i <= maxn; i++){
        int cnt = 0;
        for(int curr = 1; curr<= n; curr++){
            int pre = par[curr][i-1];
            if(pre==0)continue;
            par[curr][i] = par[pre][i-1];
            if(par[curr][i]!=0)cnt++;
        }
        if(cnt == 0) break;
    }
    while(m--){
        int a, b;
        cin>>a>>b;
        if(d[a]<d[b]) swap(a,b);
        dp[a]++;
        int A = a, B= b;
        int level = d[a]-d[b];
        for(int i = maxn; i>=0; i--){
            if((1ll<<i)<=level){
                a = par[a][i];
                level -= (1ll<<i);
            }
            if(level==0||a==-1)break;
        }

        for(int i = maxn; i>=0; i--){
            if(par[a][i]!=par[b][i]){
                a = par[a][i];
                b = par[b][i];
            }
        }
        if(a==b) dp[ par[B][0] ]--;
        else{
            int lca = par[a][0];
            dp[par[lca][0]]--;
            dp[lca]--;
            dp[B]++;
        }
    }
    dfs1(1,0);
    for(int i = 1; i <= n; i++) cout<<dp[i]<<" ";
    cout<<endl;
    return 0;
}