#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int vsize = 2e5;
ll stree[4*vsize+4], upd[4*vsize+4];
bool lazy[4*vsize+4];

void apply(int v, int tl, int tr, ll val){
    
    stree[v] += val*(tr-tl+1);

    if(tl!=tr){
        lazy[v] = true;
        upd[v]+= val;
    }
}
void pushdown(int v, int tl, int tr){
    if(!lazy[v]) return;
    lazy[v] = false;
    int tm = (tl+tr)/2;
    apply(2*v, tl, tm, upd[v]);
    apply(2*v+1, tm+1, tr, upd[v]);
    upd[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll u){
    if(l>tr || r<tl)return ;
    if(l<=tl && tr<=r){
        apply(v, tl, tr, u);
        return;
    }
    pushdown(v, tl, tr);

    int tm = (tl+tr)/2;

    update(2*v, tl, tm, l, r, u);
    update(2*v+1, tm+1, tr, l, r, u);

    stree[v] = stree[2*v] + stree[2*v+1];

}

ll query(int v, int tl, int tr, int l, int r){
    if(l>tr || r<tl) return 0;
    if(l<=tl && tr<=r) return stree[v];
    pushdown(v, tl , tr);
    int tm = (tl+tr)/2;

    return query(2*v, tl, tm, l, r) + query(2*v+1, tm+1, tr, l , r);
}
int main(){
    int n, q; cin>>n>>q;
    vector<ll> x(n);
    for(int i = 0 ; i < n; i++) cin>>x[i];
    for(int i = 0; i < n; i++){
        update(1, 0, n-1, i, i, x[i]);
    }
    while(q--){
        int t; cin>>t;
        if(t==1){
            ll a, b, u;
            cin>>a>>b>>u;
            //cout<<(query(1,0,n-1, b-2,b-2))<<" ";
            update(1, 0, n-1, a-1, b-1, u);
            //cout<<(query(1,0,n-1, b-2,b-2))<<" ";
        }
        else{
            int k; cin>>k;
            ll ans = query(1, 0, n-1, k-1, k-1);
            cout<<ans<<endl;
        }
    }
    return 0;
}