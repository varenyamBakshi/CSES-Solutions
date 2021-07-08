#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1, vector<int> (b+1, INT_MAX-10));
    for(int i = 1; i<=a; i++){
        for(int j= 1; j<= b; j++){
            if(i==1) dp[i][j] = j-1;
            else if(j==1) dp[i][j] = i-1;
            else if(i==j)dp[i][j] = 0;
            else{
                for(int k = 1; k<i; k++){
                    dp[i][j] = min(dp[i][j], 1+ dp[k][j] + dp[i-k][j]);
                }
                for(int k = 1; k<j; k++){
                    dp[i][j] = min(dp[i][j], 1+ dp[i][k] + dp[i][j-k]);
                }
            }
        }
    }
    cout<<dp[a][b];
    return 0;
}