#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const ll INF = 1e18;

struct edge{
    ll a, b, wt;
};

int main(){
    int n, m; cin>>n>>m;
    vector<edge> arr(m);
    for(int i = 0; i < m ;i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].wt;
    }
    vector<ll> dist(n+1, INF), par(n+1, -1), vis(n+1, 0);
    ll last = -1;
    for(int start = 1; start<= n; start++){
        if(vis[start])continue;
        fill(dist.begin(), dist.end(), INF);
        dist[start] = 0;
        vis[start] = 1;
        bool change = false;
        for(int i = 0; i < n; i++){
            change = false;
            for(int k = 0; k < m; k++){
                if( dist[ arr[k].a]< INF){
                    if(dist[arr[k].a] + arr[k].wt < dist[arr[k].b] ){
                    dist[arr[k].b] = dist[arr[k].a] + arr[k].wt;
                    par[arr[k].b] = arr[k].a;
                    vis[arr[k].b] = 1;
                    change = true;
                    }
                }
            }
            if(!change)break;
        }
        if(!change) continue;
        for(int k = 0; k < m; k++){
            if(dist[arr[k].a] < INF && dist[arr[k].a] + arr[k].wt < dist[arr[k].b]){
                last = arr[k].b;
                break;
            }
        }
        if(last != -1)break;
    }

    if(last==-1)cout<<"NO\n";
    else{
        cout<<"YES\n";
        for(int i = 0; i < n; i++) last = par[last];
        ll start = last;
        vector<ll> ans;
        do{
            ans.push_back(last);
            last = par[last];
        }while(last!=start);
        ans.push_back(start);
        reverse(ans.begin(), ans.end());
        for(auto it: ans) cout<<it<<" ";
    }
    return 0;
}