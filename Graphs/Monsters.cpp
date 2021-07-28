#include<bits/stdc++.h>
using namespace std;

int n, m; 
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
unordered_map<int, char> dir = { {0, 'D'}, {1, 'L'}, {2, 'R'}, {3, 'U'} };

bool isvalid(int i, int j, vector<vector<char>> &grid){
    return (i>=0 && j>=0 && i<n && j<m && grid[i][j]!='#');
}

int main(){
    cin>>n>>m;
    pair<int, int> start;
    vector<vector<char>> grid(n, vector<char> (m));
    vector<vector<int>> monster(n, vector<int> (m,INT_MAX-1));
    queue<pair<int,int>> mon;
    for(int i = 0; i  <n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A') start = {i,j};
            if(grid[i][j]=='M'){
                mon.push({i,j});
                monster[i][j] = 0;
            }
        }
    }
    while(!mon.empty()){
        auto curr = mon.front();
        mon.pop();
        int i = curr.first, j = curr.second;
        for(int k = 0; k < 4; k++){
            int x = i + dx[k], y = j + dy[k];
            if(isvalid(x, y, grid) && monster[x][y]==INT_MAX-1){
                monster[x][y] = monster[i][j] + 1;
                mon.push({x, y});
            }
        }
    }
    vector<vector<int>> dp(n, vector<int> (m,-1));
    dp[start.first][start.second] = 0;
    queue<pair<int,int>> bfs;
    bfs.push(start);
    pair<int, int> end = {-1,-1};

    while(!bfs.empty()){
        auto curr = bfs.front();
        bfs.pop();
        int i = curr.first, j = curr.second;
        if(i==0||i==n-1 || j==0 || j==m-1){
            end = {i,j};
            break;
        }
        for(int k = 0; k < 4; k++){
            int x = i + dx[k], y = j + dy[k];
            if(isvalid(x, y, grid) && dp[x][y]==-1 && monster[x][y]>dp[i][j]+1){
                dp[x][y] = dp[i][j] + 1;
                bfs.push({x, y});
                
            }
        }
    }
    if(end.first==-1) cout<<"NO\n";
    else{
        cout<<"YES\n";
        int path = dp[end.first][end.second];
        cout<<path<<endl;
        string ans = "";
        int i = end.first, j = end.second;
        while(path){
            for(int k = 0; k < 4; k++){
                int x = i + dx[k], y = j + dy[k];
                if(isvalid(x, y, grid) && dp[x][y]==path-1){
                    ans += dir[k];
                    path--;
                    i = x;
                    j = y;
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout<<ans;
    }
    // for(int)
    return 0;
}