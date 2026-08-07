class Solution {
public:
    bool pathExist(vector<vector<int>> &grid,int mid,vector<vector<int>> &dist){
        int n = grid.size();
         if(dist[0][0] < mid || dist[n-1][n-1] < mid){
            return false;
        }
        queue<pair<int,int>> q;
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        q.push({0,0});
        vector<vector<int>> vis(n,vector<int>(n,0));

        vis[0][0] = 1;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx == n-1 && ny == n-1){
                    return true;
                }

                if(nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] >= mid && !vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }

        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == INT_MAX){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }

        int l = 0,r = n*n-1;
        int ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(pathExist(grid,mid,dist)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }

        }
        return ans;
    }
};