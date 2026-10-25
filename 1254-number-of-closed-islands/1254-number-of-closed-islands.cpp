class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    void bfs(vector<vector<int>> &vis,int i,int j,vector<vector<int>> &grid,int m,int n){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int j=0;j<n;j++){
            if(grid[0][j] == 0 && !vis[0][j]){
                bfs(vis,0,j,grid,m,n);
            }

            if(grid[m-1][j] == 0 && !vis[m-1][j]){
                bfs(vis,m-1,j,grid,m,n);
            }
        }

        for(int i=0;i<m;i++){
            if(grid[i][0] == 0 && !vis[i][0]){
                bfs(vis,i,0,grid,m,n);
            }

            if(grid[i][n-1] == 0 && !vis[i][n-1]){
                bfs(vis,i,n-1,grid,m,n);
            }
        }
        
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    bfs(vis,i,j,grid,m,n);
                    count++;
                }
            }
        }

        return count;
    }
};