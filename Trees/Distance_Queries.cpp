#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int vsize = 2e5+5;
vector<int> adj[vsize+1];
int d[vsize+1];

void dfs(int x, int prev, vector<vector<int>> &par){
    for(auto child: adj[x]){
        if(child==prev) continue;
        par[child][0] = x;
        d[child] = d[x] + 1;
        dfs(child, x, par);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin>>n>>q;
    for(int i = 2; i <=n; i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int maxn = log2(n)+1;
    vector<vector<int>> par(n+1, vector<int>(maxn+1,-1));
    d[1] = 0;
    dfs(1, -1, par);

    for(int i = 1; i <= maxn; i++){
        int cnt = 0;
        for(int curr = 1; curr<= n; curr++){
            int pre = par[curr][i-1];
            if(pre==-1)continue;
            par[curr][i] = par[pre][i-1];
            if(par[curr][i]!=-1)cnt++;
        }
        if(cnt == 0) break;
    }
    while(q--){
        int a, b;
        cin>>a>>b;
        
        if(d[a]<d[b]) swap(a,b);
        int A = a, B= b;
        int level = d[a]-d[b];
        int cnt = maxn;
        for(int i = (1ll<<maxn); i>0; i>>=1){
            if(i<=level){
                a = par[a][cnt];
                level -= i;
            }
            if(level==0||a==-1)break;
            cnt--;
        }
        if(a==b) cout<<d[A]-d[B]<<endl;
        else{
            for(int i = maxn; i>=0; i--){
                if(par[a][i]!=par[b][i]){
                    a = par[a][i];
                    b = par[b][i];
                }
            }
            int lca = par[a][0];
            cout<<(d[A] + d[B] - 2*d[lca])<<endl;
        }
    }
    return 0;
}