#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define ff first
#define ss second
const ll vsize = 2e5+5;
ll pos[vsize+1], subtree[vsize+1], val[vsize+1], pre[vsize+1];
vector<ll> adj[vsize+1];
ll timer = 0;

vector<ll> stree;
vector<bool> lazy;
vector<ll> upd;

// tl and tr represents segment ranges everywhere
// v represent index of current node in stree[]

void apply(ll v, ll tl, ll tr, ll val){  // asking the node to update its result
    stree[v] += val*(tr-tl+1);   // updating its value

    if(tl!=tr){          // its not a leaf
        lazy[v] = true;  // mark it lazy
        upd[v] += val;   // making it remember the update which will later be passed on to children
    }
}

void pushdown(ll v, ll tl, ll tr){
    if(!lazy[v]) return; // if not lazy then nothing to do
    lazy[v] = false;    // removing the lazy tag

    ll tm = (tl+tr)/2;
    apply(2*v, tl, tm, upd[v]);        // passing on the value
    apply(2*v+1, tm+1, tr, upd[v]);    // to children
    upd[v] = 0;
}

// l and r are the update range
// val is the value to be added
void update(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l>tr || r<tl)return;                    // no overlap
    if(tl>=l && tr<=r){                        // fully within
        apply(v, tl, tr, val);
        return;               //instead of passing down the update we ask the node to remember it
    }
    pushdown(v, tl, tr);      // before going down we ask the node to push down its knowledge to its children 

    ll tm = (tl+tr)/2;
    update(2*v, tl, tm, l, r, val);
    update(2*v+1, tm+1, tr, l, r, val);
    stree[v] = stree[2*v] + stree[2*v+1];
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(l>tr || r<tl) return 0;                 // no overlap
    if(tl>=l && tr<=r) return stree[v];        // fully within. Note: value of stree[v] is correct
    pushdown(v, tl, tr);      // before going down we ask the node to push down its knowledge to its children

    ll tm = (tl+tr)/2;
    return query(2*v, tl, tm, l, r) + query(2*v+1, tm+1, tr, l, r);
    // passing answer returned from children
}

void dfs(ll node, ll par){
    pos[node] = timer++;
    subtree[node] = 1;
    pre[node] = val[node] + pre[par];
    for(auto child: adj[node]){
        if(child == par)continue;
        dfs(child, node);
        subtree[node] += subtree[child];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q;
    cin>>n>>q;

    for(ll i = 1; i <= n; i++) cin>>val[i];
    for(ll i = 0; i < n-1; i++){
        ll x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }    
    dfs(1, 0);
    stree.resize(4*n+4,0);
    lazy.resize(4*n+4,false);
    upd.resize(4*n+4,0);
    //cout<<stree[2];
    
    //for(ll i = 1; i <= n; i++) cout<<pos[i];
    for(ll i = 1; i <= n; i++){
        update(1,0,n-1, pos[i], pos[i], pre[i]);
    }
    while(q--){
        ll type; cin>>type;
        if(type==1){
            ll node, vl;
            cin>>node>>vl;
            ll v = vl;
            vl -= val[node];
            val[node] = v;
            ll len = subtree[node];
            update(1, 0, n-1, pos[node], pos[node]+len-1, vl);
        }
        else{
            ll node; cin>>node;
            //ll len = subtree[node];
            ll ans = query(1, 0, n-1, pos[node], pos[node]);
            cout<<ans<<endl;
        }
    }
    return 0;
}   