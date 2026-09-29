class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == ')'){
            return false;
        }

        vector<vector<unordered_set<int>>> dp(m,vector<unordered_set<int>>(n));
        dp[0][0].insert(1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int val = (grid[i][j] == '(')?1:-1;
                if(i > 0){
                    for(auto x : dp[i-1][j]){
                        if(x+val >= 0){
                         dp[i][j].insert(x+val);
                        }
                    }
                }
                if(j > 0){
                    for(auto x : dp[i][j-1]){
                        if(x+val >= 0){
                           dp[i][j].insert(x+val);
                        }  
                    }
                }
            }
        }

        if(dp[m-1][n-1].count(0)){
            return true;
        }
        return false;
    }
};