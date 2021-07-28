// USE SETS FOR IMPLEMENTING DJIKSTRA NOT PRIORITY_QUEUE

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

struct edge{
    ll b, wt;
    edge(ll j, ll c){b = j; wt = c;};
};

const int vsize = 1e5;
vector<edge> adj[vsize+1];
ll dist[vsize+1];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        ll a, b, c; cin>>a>>b>>c;
        adj[a].push_back(edge(b,c));
    }
    fill(dist , dist + n+1, LONG_MAX/10);
    set<pair<ll, ll>> bag;
    dist[1] = 0;
    bag.insert({0, 1});
    while(!bag.empty()){
        auto curr = *bag.begin();
        bag.erase(bag.begin());
        ll d = curr.first, node = curr.second;
        for(auto child: adj[node]){
            if(dist[child.b] > d + child.wt){
                if(dist[child.b]<LONG_MAX/10) bag.erase({dist[child.b], child.b});
                dist[child.b] = d + child.wt;
                bag.insert({dist[child.b], child.b});
            }
        }
    }
    for(int i = 1; i <= n; i++)cout<<dist[i]<<" ";
    return 0;
}