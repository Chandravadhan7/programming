class Solution {
public:
    int topdown(int i,int j,vector<vector<int>> &dp,vector<int> &nums){
        if(i == j){
            return nums[i];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int maax = max(nums[i]-topdown(i+1,j,dp,nums),nums[j]-topdown(i,j-1,dp,nums));

        return dp[i][j] = maax;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return topdown(0,n-1,dp,nums)>=0;
    }
};