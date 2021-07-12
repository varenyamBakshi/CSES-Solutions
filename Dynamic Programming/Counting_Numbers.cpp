#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> pow9(20);

void init(){
    pow9[0] = 1;
    for(int i = 1; i < 20; i++) pow9[i] = (pow9[i-1]*9);
}

ll solve(string & num){
    
    int n = num.length();
    num.insert(0, "A");
    ll ans = 0;
    for(int i= 1; i<= n; i++){
        int curr = num[i]-'0';
        if(num[i]>num[i-1]) curr--;
        if(i==1){
            for(int i = 2; i<= n; i++ ){
                ans += pow9[n-i];
            }
        }
        // cout<<"curr:"<<curr<<endl;
        ans += curr*pow9[n-i];
        // cout<<ans<<" ";
        if(num[i]==num[i-1]) break;
        if(i==n)ans++;
    }
    // cout<<ans<<endl;
    return ans;
}

int main(){
    init();
    ll a, b; cin>>a>>b;
    a--;
    string R = to_string(b);
    string L;
    if(a>=0) L = to_string(a);
    else L = "0";
    ll l = solve(L), r = solve(R);
    //cout<<l<<" "<<r<<endl;
    ll ans = r - l;
    if(a<0)ans++;
    cout<<ans;
    return 0;
}