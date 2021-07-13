class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        vis[entrance[0]][entrance[1]] = true;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto p = q.front();
                int i = p.first, j = p.second;
                q.pop();
                if((i==n-1 || i==0 || j==m-1 || j==0) && (i!=entrance[0] || j!=entrance[1])){
                    return cnt;
                }
                if(i-1>=0 && !vis[i-1][j] && maze[i-1][j]=='.'){
                    vis[i-1][j] = true;
                    q.push({i-1,j});
                }
                if(j-1>=0 && !vis[i][j-1] && maze[i][j-1]=='.'){
                    vis[i][j-1] = true;
                    q.push({i,j-1});
                }
                if(i+1<n && !vis[i+1][j] && maze[i+1][j]=='.'){
                    vis[i+1][j] = true;
                    q.push({i+1,j});
                }
                if(j+1<m && !vis[i][j+1] && maze[i][j+1]=='.'){
                    vis[i][j+1] = true;
                    q.push({i,j+1});
                }
            }
            cnt++;
        }
        return -1;
    }
};