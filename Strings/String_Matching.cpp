#include<bits/stdc++.h>
using namespace std;

int main(){
    string pat, text; 
    cin>>text; cin>>pat;
    int n = text.length(), m = pat.length();
    string word = pat + "#" + text;
    vector<int> pi((int)word.length());
    pi[0] = 0;
    for(int i =1; i< word.length(); i++){
        int j = pi[i-1];
        while(j>0 && word[i] != word[j]) j = pi[j-1];
        if(word[i]==word[j]) pi[i] = j+1;
        else pi[i] = 0;
    }
    int ans = 0;
    for(int i = m+1; i< word.length(); i++){
        if(pi[i]==m)ans++;
    }
    cout<<ans;
    return 0;
}