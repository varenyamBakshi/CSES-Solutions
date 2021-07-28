#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const int vsize = 1e5;
const int M = 1e9+7;
const ll INF = 1e18;
vector<vector<ll>> adj[vsize+1];

int main(){
    int n, m; cin>>n>>m;
    for(int i = 0; i <m; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<vector<ll>> det(n+1, vector<ll>(3));
    vector<ll> dist(n+1, INF);
    dist[1] = 0;
    det[1] = {1, 0, 0};
    set<pair<ll,ll>> bag; 
    bag.insert({0,1});
    while(!bag.empty()){
        auto curr = *bag.begin();
        bag.erase(bag.begin());
        ll node = curr.second, d = curr.first;
        for(auto child: adj[node]){
            if(dist[child[0]] > d + child[1]){
                if(dist[child[0]]<INF) bag.erase({dist[child[0]], child[0]});
                dist[child[0]] = d + child[1];
                det[child[0]][0] = det[node][0]%M;
                det[child[0]][1] = det[node][1] + 1;
                det[child[0]][2] = det[node][2] + 1;
                bag.insert({dist[child[0]], child[0]});
            }
            else if(dist[child[0]] == d + child[1]){
                det[child[0]][0] += det[node][0];
                det[child[0]][0] %= M;
                det[child[0]][1] = min(det[node][1] + 1, det[child[0]][1] );
                det[child[0]][2] = max(det[node][2] + 1, det[child[0]][2] );
            }
        }
    }
    cout<<dist[n]<<" "<<det[n][0]<<" "<<det[n][1]<<" "<<det[n][2];
    return 0;
}