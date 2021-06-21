#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define ff first
#define ss second
const int vsize = 2e5+5;
ll pos[vsize+1], subtree[vsize+1];
vector<int> adj[vsize+1];
int timer = 0;

vector<ll> stree;
vector<bool> lazy;
vector<ll> upd;

// tl and tr represents segment ranges everywhere
// v represent index of current node in stree[]

void apply(int v, int tl, int tr, int val){  // asking the node to update its result
    stree[v] = val;   // updating its value

    if(tl!=tr){          // its not a leaf
        lazy[v] = true;  // mark it lazy
        upd[v] = val;   // making it remember the update which will later be passed on to children
    }
}

void pushdown(int v, int tl, int tr){
    if(!lazy[v]) return; // if not lazy then nothing to do
    lazy[v] = false;    // removing the lazy tag

    int tm = (tl+tr)/2;
    apply(2*v, tl, tm, upd[v]);        // passing on the value
    apply(2*v+1, tm+1, tr, upd[v]);    // to children
    upd[v] = 0;
}

// l and r are the update range
// val is the value to be added
void update(int v, int tl, int tr, int l, int r, int val){
    if(l>tr || r<tl)return;                    // no overlap
    if(tl>=l && tr<=r){                        // fully within
        apply(v, tl, tr, val);
        return;               //instead of passing down the update we ask the node to remember it
    }
    pushdown(v, tl, tr);      // before going down we ask the node to push down its knowledge to its children 

    int tm = (tl+tr)/2;
    update(2*v, tl, tm, l, r, val);
    update(2*v+1, tm+1, tr, l, r, val);
    stree[v] = stree[2*v] + stree[2*v+1];
}

ll query(int v, int tl, int tr, int l, int r){
    if(l>tr || r<tl) return 0;                 // no overlap
    if(tl>=l && tr<=r) return stree[v];        // fully within. Note: value of stree[v] is correct
    pushdown(v, tl, tr);      // before going down we ask the node to push down its knowledge to its children

    int tm = (tl+tr)/2;
    return query(2*v, tl, tm, l, r) + query(2*v+1, tm+1, tr, l, r);
    // passing answer returned from children
}

void dfs(int node, int par){
    pos[node] = timer++;
    subtree[node] = 1;
    for(auto child: adj[node]){
        if(child == par)continue;
        dfs(child, node);
        subtree[node] += subtree[child];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n>>q;
    vector<ll> val(n+1);
    for(int i = 1; i <= n; i++) cin>>val[i];
    for(int i = 0; i < n-1; i++){
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }    
    dfs(1, -1);
    stree.resize(4*n+4,0);
    lazy.resize(4*n+4,false);
    upd.resize(4*n+4,0);
    //cout<<stree[2];
    
    //for(int i = 1; i <= n; i++) cout<<pos[i];
    for(int i = 1; i <= n; i++){
        update(1,0,n-1, pos[i], pos[i], val[i]);
    }
    while(q--){
        int type; cin>>type;
        if(type==1){
            ll node, val;
            cin>>node>>val;

            update(1, 0, n-1, pos[node], pos[node], val);
        }
        else{
            ll node; cin>>node;
            int len = subtree[node];
            ll ans = query(1, 0, n-1, pos[node], pos[node]+len-1);
            cout<<ans<<endl;
        }
    }
    return 0;
}   