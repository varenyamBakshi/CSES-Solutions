#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define ff first
#define ss second

const int vsize = 2e5;
ll stree[vsize*4], upd[vsize*4];
ll lazy[vsize*4];

void apply(ll v, ll tl, ll tr, ll val){
    stree[v] += val;
    
    if(tl!= tr){
        lazy[v] = true;
        upd[v] += val;
    }
}

void pushdown(ll v, ll tl, ll tr){
    if(!lazy[v]) return;
    lazy[v] = false;
    ll tm = (tl+tr)/2;
    apply(2*v, tl, tm, upd[v]);
    apply(2*v+1, tm+1, tr, upd[v]);
    upd[v] = 0ll;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l>tr || r < tl)return;
    if(l<=tl && tr<=r){
        apply(v, tl, tr, val);
        return;
    }
    pushdown(v, tl, tr);
    ll tm = (tl+tr)/2;
    update(2*v, tl, tm, l, r, val);
    update(2*v+1, tm+1, tr, l, r, val);
    stree[v] = max(stree[2*v], stree[2*v+1]);
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(l>tr || r <tl)return (ll)LONG_MIN;
    if(l<=tl && tr<=r){
        return stree[v];
    }
    pushdown(v, tl, tr);
    ll tm = (tl+tr)/2;
    return max(query(2*v, tl, tm, l, r), query(2*v+1, tm+1, tr, l, r));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,q; cin>>n>>q;
    vector<ll> x(n);
    for(ll i = 0; i < n; i++) cin>>x[i];
    vector<ll> pre(n);
    pre[0] = x[0];
    ll va = LONG_MIN/100;
    for(ll i = 0; i < 4*n; i++) stree[i] = va;
    //cout<<stree[1]<<" ";
    for(ll i = 1; i < n; i++)pre[i] = pre[i-1] + x[i];
    for(ll i = 0; i <n; i++)update(1, 0, n-1, i, i, pre[i]);
    while(q--){
        ll t; cin>>t;
        if(t==1){
            ll k, u;
            cin>>k>>u;
            ll value = u - x[k-1];
            x[k-1] = u;
            update(1, 0, n-1, k-1, n-1, value);
        }
        else{
            ll a, b;
            cin>>a>>b;
            ll ans = query(1, 0, n-1, a-1, b-1);
            if(a>1) ans -= query(1, 0, n-1, a-2, a-2);
            ans = max(ans, 0ll);
            cout<<ans<<endl;
        }
    }
    return 0;
}