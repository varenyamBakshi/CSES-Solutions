#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

class DSU{
    public: 
    struct node{
        int par;
        int size;
    };
    int maxc, num;
    vector<node> city;

    
    DSU(int n){
        maxc = 1;
        num = n;
        city.resize(n+1);
        for(int i = 1; i <= n; i++){
            city[i].par =i;
            city[i].size = 1;
        }
    }

    int find(int x){
        stack<int> ele;
        while(city[x].par != x){
            ele.push(x);
            x = city[x].par;
        }
        while(!ele.empty()){
            int curr = ele.top();
            city[curr].par = x;
            ele.pop();
        }
        return x;
    }
    void makeunion(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b)return;

        int root = (city[a].size >= city[b].size)? a: b;
        city[a].par = city[b].par = root;
        city[root].size = city[a].size + city[b].size;
        maxc = max(maxc, city[root].size);
        num--;
    }

};

int main(){
    int n, m; cin>>n>>m;
    vector<pair<int,int>> roads(m);
    for(int i = 0; i < m; i++){
        cin>> roads[i].first >> roads[i].second;
    }
    DSU dsu(n);
    for(auto road: roads){
        int a = road.first, b = road.second;
        dsu.makeunion(a, b);
        cout<<dsu.num << " " << dsu.maxc <<endl;
    }
    return 0;
}