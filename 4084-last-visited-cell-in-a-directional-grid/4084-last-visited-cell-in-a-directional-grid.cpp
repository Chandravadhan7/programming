class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int x=0,y=0;
        int i=0,j=0;
        while(i >= 0 && j >=0 && i < n && j < m && !vis[i][j]){
            vis[i][j] = 1;
            x = i,y = j;

            if(grid[i][j] == 'L'){
                j=j-1;
            }else if(grid[i][j] == 'R'){
                j=j+1;
            }else if(grid[i][j] == 'U'){
                i=i-1;
            }else{
                i=i+1;
            }
        }
        return {x,y};
    }
};