#include<bits/stdc++.h>
using namespace std;

int main(){
    string text; cin>>text;
    int n = text.length();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i = 1; i <n; i++){
        int j = pi[i-1];
        while(j>0 && text[i]!=text[j]) j = pi[j-1];
        if(text[i]==text[j])pi[i] = j+1;
        else pi[i] = 0;
    }
    vector<int> ans;
    int j = pi[n-1];
    while(j>0){
        ans.push_back(j);
        j = pi[j-1];
    }
    for(int i = ans.size()-1; i>=0; i--) cout<<ans[i]<<" ";
    return 0;
}