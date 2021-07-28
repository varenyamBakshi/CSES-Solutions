#include<bits/stdc++.h>
using namespace std;

int n, m; 
int dx[] = {-1, 0 ,0, 1};
int dy[] = {0, 1, -1, 0};
unordered_map<int, char> dir = {{0,'D'},{1, 'L'}, {2,'R'}, {3, 'U'}};

bool isvalid(int x, int y, vector<vector<char>> &grid){
    return (x>=0 && y>=0 && x<n && y< m && grid[x][y]!='#');
}

int main(){
    cin>>n>>m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    pair<int,int> start, end;
    for(int i = 0; i  <n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A') start = {i,j};
            if(grid[i][j]=='B') end = {i,j};
        }
    }
    queue<pair<int,int>> bfs;
    bfs.push(start);
    vector<vector<int>> dp(n, vector<int> (m,-1));
    dp[start.first][start.second] = 0;
    while(!bfs.empty()){
        auto curr = bfs.front();
        bfs.pop();
        int x = curr.first, y = curr.second;
        for(int i = 0; i < 4; i++){
            int x1 = x + dx[i], y1 = y+ dy[i];
            if(isvalid(x1, y1, grid) && dp[x1][y1]==-1){
                dp[x1][y1] = dp[x][y]+1;
                bfs.push({x1, y1});
            }
        }
    }
    // for(int i = 0 ; i < n; i++){
    //     for(int j = 0; j < m; j++)cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    if(dp[end.first][end.second]==-1) cout<<"NO\n";
    else{
        cout<<"YES\n";
        cout<<dp[end.first][end.second]<<endl;
        string ans = "";
        int i = end.first, j = end.second;
        int path = dp[end.first][end.second];
        while(path){
            for(int k = 0; k < 4; k++){
                if(isvalid(i + dx[k], j + dy[k], grid) && dp[i+dx[k]][j+dy[k]]==path-1){
                    ans += dir[k];
                    i = i+dx[k];
                    j = j + dy[k];
                    path--;
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
    }
    return 0;
}