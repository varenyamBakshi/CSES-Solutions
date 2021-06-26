#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
vector<ll> stree;

void build(ll v, ll tl, ll tr,vector<ll> &arr){
    if(tl==tr){
        stree[v] = arr[tl];
        return;
    }
    ll tm = tl + (tr-tl)/2;
    build(2*v, tl, tm, arr);
    build(2*v+1, tm+1, tr, arr);
    stree[v] = stree[2*v] + stree[2*v+1];
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tr<l || tl > r) return 0;
    if(tl>=l && tr <= r){
        return stree[v];
    }
    ll tm = tl + (tr-tl)/2;
    return query(2*v, tl, tm, l, r) + query(2*v+1, tm+1, tr, l, r);
}

void update(ll v, ll tl, ll tr, ll pos, ll val){
    if(pos>tr || pos<tl) return;
    if(tl== pos && tr==pos) {
        stree[v] = val;
        return;
    }
    ll tm = tl + (tr-tl)/2;
    update(2*v, tl ,tm, pos, val);
    update(2*v+1, tm+1, tr, pos, val);
    stree[v] = stree[2*v] + stree[2*v+1];
}

int main(){
    int n, q; cin>>n>>q;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];

    stree.resize(4*n);
    build(1, 0, n-1, arr);
    while(q--){
        int t; cin>>t;
        if(t==1){
            ll k, u; cin>>k>>u;
            update(1, 0, n-1, k-1, u);
        }
        else{
            ll x, y; cin>>x>>y;
            cout<<query(1, 0, n-1, x-1, y-1)<<endl;
        }
    }
    return 0;
}