class Solution {
public:
    bool dfs(int i,int j,int px,int py,vector<vector<int>> &vis,vector<vector<char>> &grid){
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,-1,0,1};
        vis[i][j] = 1;
        for(int d=0;d<4;d++){
            int nx = i + dx[d];
            int ny = j + dy[d];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == grid[i][j]){
                if(vis[nx][ny] == 0){
                    if(dfs(nx,ny,i,j,vis,grid)){
                        return true;
                    }
                }else if(nx != px && ny != py){
                    return true;
                }
            }
        }

        return false;

    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,vis,grid)){
                    return true;
                    }
                }
            }
        }
        return false;
    }
};