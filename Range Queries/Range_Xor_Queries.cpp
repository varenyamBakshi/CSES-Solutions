#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
    int n, q; cin>>n>>q;
    vector<ll> a(n+1,0);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) a[i]^=a[i-1];
    while(q--){
        int x, y;
        cin>>x>>y;
        ll ans = a[y]^a[x-1];
        cout<<ans<<endl;
    }
    return 0;
}