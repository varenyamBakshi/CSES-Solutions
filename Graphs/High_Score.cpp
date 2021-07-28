#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl "\n"
const ll INF = 1e17;

struct edge{
    ll a, b, wt;
};

int main(){
    int n,m; cin>>n>>m;
    vector<edge> arr;
    for(int i = 0; i < m; i++){
        edge t; cin>>t.a>>t.b>>t.wt;
        t.wt *= -1;
        arr.push_back(t);
    }
    vector<ll> dist(n+1, INF);
    dist[1] = 0;
    for(int i = 0; i < 2*n; i++){
        for(int k = 0; k < m; k++){
            edge curr = arr[k];
            if( dist[ curr.a]<INF) {
                if(dist[curr.a] + curr.wt < dist[curr.b]){
                    if(i>=n) dist[curr.b]=-1*INF;
                    else dist[curr.b] = dist[curr.a] + curr.wt;
                    
                }
            }
        }
        //if(i==n-1)ans = dist[n];
    }
    if(dist[n]<=-1*INF) cout<<-1<<endl;     
    else cout<<-1*dist[n];

    return 0;
}