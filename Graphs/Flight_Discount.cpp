#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
const ll INF = 1e18;
 
void dij(ll start, vector<ll> & dist, vector<vector<vector<ll>>> &adj){
    dist[start] = 0;
    set<pair<ll,ll>> bag;
    bag.insert({0, start});
    while(!bag.empty()){
        auto curr = *bag.begin();
        bag.erase(bag.begin());
        ll node = curr.second, d = curr.first;
        for(auto child: adj[node]){
            if(d+child[1] < dist[child[0]]){
                if(dist[child[0]]<INF) bag.erase({dist[child[0]], child[0]});
                dist[child[0]] = d + child[1];
                bag.insert({dist[child[0]], child[0]});
            }
        }
    }
}
 
int main(){
    int n, m; cin>>n>>m;
    vector<vector<vector<ll>>> adj(n+1), revadj(n+1);
    for(int i = 0; i < m ; i++){
        int a, b, wt;
        cin>>a>>b>>wt;
        adj[a].push_back({b, wt});
        revadj[b].push_back({a, wt});
    }
    vector<ll> dist1(n+1, INF), distn(n+1, INF);
    dij(1, dist1, adj);
    dij(n, distn, revadj);
    ll ans = dist1[n];
    for(int i = 1; i <= n; i++){
        for(auto child: adj[i]){
            ll d = dist1[i] + distn[child[0]] + child[1]/2;
            ans = min(ans, d);
        }
    }
    cout<<ans;
    return 0;
}