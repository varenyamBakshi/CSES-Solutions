#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(){
    int n; cin>>n;
    vector<int> dp(n+1,INT_MAX-10);
    dp[0] = 0;
    for(int i = 1; i<= n; i++){
        int temp = i;
        vector<int> dig;
        while(temp){
            dig.push_back(temp%10);
            temp/=10;
        }
        for(auto it: dig){
            dp[i] = min(dp[i], dp[i-it] + 1);
        }
    }
    cout<<dp[n];
    return 0;
}