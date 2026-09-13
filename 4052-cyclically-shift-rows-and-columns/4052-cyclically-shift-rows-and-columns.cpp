class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0;i<n;i++){
            int k = rowShift[i]%n;
            reverse(grid[i].begin(),grid[i].end());
            reverse(grid[i].begin(),grid[i].begin()+n-k);
            reverse(grid[i].begin()+n-k,grid[i].end());
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               swap(grid[i][j],grid[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            int k = colShift[i]%n;
            reverse(grid[i].begin(),grid[i].end());
            reverse(grid[i].begin(),grid[i].begin()+n-k);
            reverse(grid[i].begin()+n-k,grid[i].end());
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               swap(grid[i][j],grid[j][i]);
            }
        }
        
        return grid;

    }
};