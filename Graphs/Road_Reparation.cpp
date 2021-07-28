#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

struct edge{
    ll a, b, wt;
};

bool comp(edge x, edge y){
    return x.wt<=y.wt;
}

class DSU{
    struct node{
        int par;
        int rank;
    };

    vector<node> arr;
    public: 

    DSU(int n){
        arr.resize(n+1);
        for(int i = 1; i <= n; i++){
            arr[i].par = i;
            arr[i].rank = 0;
        }
    }

    int find( int x){
        stack<int> ele;
        while(arr[x].par!=x){
            ele.push(x);
            x = arr[x].par;
        }
        while(!ele.empty()){
            int curr = ele.top();
            arr[curr].par = x;
            ele.pop();
        }
        return x;
    }

    bool makeunion(int a, int b){
        int na = find(a);
        int nb = find(b);
        if(na==nb)return false;
        if(arr[na].rank> arr[nb].rank) arr[nb].par = na;
        else if(arr[na].rank< arr[nb].rank) arr[na].par = nb;
        else{
            arr[nb].par = na;
            arr[na].rank++;
        }
        return true;
    }
};

int main(){
    int n, m; cin>>n>>m;
    vector<edge> road(m);
    for(int i =0; i < m; i++) cin>> road[i].a >> road[i].b >> road[i].wt;  
    sort(road.begin(), road.end(), comp);
    ll ans = 0;
    DSU dsu(n);
    for(auto rd: road){
        if(dsu.makeunion(rd.a, rd.b)) ans+= rd.wt;
    }
    bool possible = true;
    for(int i = 2; i <= n; i++){
        if(dsu.find(i)!=dsu.find(1)){
            possible = false;
            break;
        }
    }
    if(!possible)cout<<"IMPOSSIBLE\n";
    else cout<<ans;
    return 0;
}