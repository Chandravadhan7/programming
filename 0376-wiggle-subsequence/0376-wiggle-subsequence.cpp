class Solution {
public:
    int topdown(int i,int sign,vector<vector<int>> &dp,vector<int> &nums){
        int n = nums.size();

        if(dp[i][sign] != -1){
            return dp[i][sign];
        }

        int ans = 1;
        for(int j=i+1;j<n;j++){
            if(sign == 0 && nums[i] < nums[j]){
                ans = max(ans,topdown(j,1,dp,nums)+1);
            }else if(sign == 1 && nums[i] > nums[j]){
                ans = max(ans,topdown(j,0,dp,nums)+1);
            }
        }
        
        return dp[i][sign] = ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans = 1;

        for(int i=0;i<n;i++){
            ans = max(ans,topdown(i,0,dp,nums));
            ans = max(ans,topdown(i,1,dp,nums));
        }

        return ans;
    }
};