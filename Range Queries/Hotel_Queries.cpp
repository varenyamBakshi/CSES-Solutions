#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int vsize = 2e5;
ll stree[4*vsize];

void update(int v, int tl, int tr, int pos, ll val){
    if(pos>tr || pos<tl) return;
    if(pos==tl && pos==tr){
        stree[v] = val;
        return;
    }
    int tm = (tl+tr)/2;
    update(2*v, tl, tm, pos, val);
    update(2*v+1, tm+1, tr, pos, val);
    stree[v] = max(stree[v*2], stree[2*v +1]);
}
ll query(int v, int tl, int tr, ll val){
    if(stree[v]<val)return 0;
    if(tl==tr){
        stree[v] -= val;
        return tl+1;
    }
    
    int tm = (tl+tr)/2;
    ll ans;
    if(stree[2*v]>=val) ans = query(2*v, tl, tm, val);
    else ans = query(2*v+1, tm+1, tr, val);
    stree[v] = max(stree[2*v], stree[2*v+1]);
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> h(n);
    for(int i  = 0; i < n; i++) cin>>h[i];
    for(int i  =0 ; i < n; i++){
        update(1, 0, n-1, i, h[i]);
    }
    //cout<<stree[1]<<endl;
    while(m--){
        ll x; cin>>x;
        ll ans = query(1, 0, n-1, x);
        cout<<ans<<" ";
    }
    return 0;
}