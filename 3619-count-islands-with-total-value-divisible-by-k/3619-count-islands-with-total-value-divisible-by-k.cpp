class Solution {
public:
    void bfs(vector<vector<int>>& grid,vector<vector<int>> &vis,int i,int j,long long& sum){
        int m = grid.size();
        int n = grid[0].size(); 
        queue<pair<int,int>> q;
        
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};

        q.push({i,j});
        while(!q.empty()){
            auto x = q.front();
            q.pop();

            vis[x.first][x.second] = 1;
            sum += grid[x.first][x.second];
 
            for(int i=0;i<4;i++){
                int nx = x.first + dx[i];
                int ny = x.second + dy[i];

                if(nx >=0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 0 && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }

        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] !=0){
                    long long sum = 0;
                    bfs(grid,vis,i,j,sum);
                    if(sum%k == 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};