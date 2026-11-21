class Solution {
public:

    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> dp(mx+2,0);
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            dp[nums[i]+1] = dp[nums[i]]+1;
            dp[nums[i]] = dp[nums[i]-1]+1;
            ans = max({ans,dp[nums[i]+1],dp[nums[i]]});
        }
        return ans;
    }
};