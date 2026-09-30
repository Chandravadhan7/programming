class Solution {
public:
    bool topdown(int i,int j,int b,vector<vector<vector<int>>> &dp,vector<vector<char>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        if(i >= m || j >= n){
            return false;
        }
        if(grid[i][j] == '(')
            b++;
        else
            b--;

        if(b < 0)
            return false;

        if(i == m - 1 && j == n - 1)
            return b == 0;

        if(dp[i][j][b] != -1)
            return dp[i][j][b];

        bool ans = topdown(i + 1, j, b, dp, grid) ||
                   topdown(i, j + 1, b, dp, grid);

        return dp[i][j][b] = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(m+n,-1)));

        return topdown(0,0,0,dp,grid);
    }
};