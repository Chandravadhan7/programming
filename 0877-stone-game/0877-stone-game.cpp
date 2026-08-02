class Solution {
public:
    int topdown(int i,int j,vector<vector<int>> &dp,vector<int> &piles){
        if(i == j){
            return piles[i];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int maax = max(piles[i]+topdown(i+1,j,dp,piles),piles[j]+topdown(i,j-1,dp,piles));

        return dp[i][j] = maax;
    }
    bool stoneGame(vector<int>& piles) {
        int n =piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return topdown(0,n-1,dp,piles)>=0;
    }
};