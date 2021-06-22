#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define ff first
#define ss second

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q; cin>>n>>q;
    vector<ll> a(n+1,0);
    for(int i = 1; i <=n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) a[i]+=a[i-1];
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<(a[y]-a[x-1])<<endl;
    }
    

    return 0;
}