#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int vsize  = 2e5;
ll stree[vsize*4];

void update(int v, int tl, int tr, int pos){
    if(pos>tr || pos < tl) return;
    if(pos==tl && pos==tr) {
        stree[v] = 1;
        return;
    }
    int tm = (tl+tr)/2;
    update(2*v, tl, tm, pos);
    update(2*v+1, tm+1, tr, pos);
    stree[v] = stree[2*v] + stree[2*v+1];
}

int query(int v, int tl, int tr, int pos){
    if(tl==tr){
        //cout<<"B";
        stree[v]--;
        return tl;
    }
    int tm = (tl + tr)/2;
    int ans;
    if(stree[2*v]>=pos) {
        //cout<<"L";
        ans = query(2*v, tl, tm, pos);
        
    }
    else{
        //cout<<"R";
        pos-=stree[2*v];
        ans = query(2*v+1, tm+1, tr, pos);
    }
    stree[v] = stree[2*v] + stree[2*v+1];
    return ans;
}

int main(){

    int n; cin>>n; 
    vector<ll> x(n);
    for(int i = 0; i < n; i++)cin>>x[i];
    for(int i = 0; i < n; i++){
        update(1, 0, n-1, i);
    }
    int m = n;
    while(m--){
        //cout<<stree[1]<<" ";
        int pos; cin>>pos;
        int id = query(1, 0, n-1, pos);
        // cout<<"  ";
        // for(int i = 0; i < 11; i++)cout<<stree[i]<<" ";
        // cout<<endl;
        cout<<x[id]<<" ";
    }
    
    return 0;
}