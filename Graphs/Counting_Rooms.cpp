#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
 
char room[1001][1001];
bool visited[1001][1001] = {false};
int dx[] = {0,-1,0,1}, dy[] ={-1,0,1,0};
 
bool isvalid(int x, int y, int n, int m){
    if(x<0||x>n-1 || y<0||y>m-1 || room[x][y]=='#'|| visited[x][y]) return false;
    else return true;
}
 
void dfs(int x, int y, int n, int m){
    visited[x][y]=true;
    for(int i = 0; i<4; i++){
        if(isvalid(x+dx[i], y+dy[i], n ,m)) dfs(x+dx[i], y+dy[i], n ,m);
    }
}
 
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int ii = 0; ii <m ; ii++){
            cin>>room[i][ii];
        }
    }
    int count = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m;j++){
            if(room[i][j] == '.' && !visited[i][j]) {
                dfs(i,j,n,m);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}