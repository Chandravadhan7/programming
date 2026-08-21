class Solution {
public:
    int topdown(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
        if(i > j){
          return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int maax = INT_MIN;

        for(int id=i;id<=j;id++){
           int ans = nums[j+1]*nums[id]*nums[i-1] + topdown(i,id-1,nums,dp) + topdown(id+1,j,nums,dp);

           maax = max(maax,ans);
        }

        return dp[i][j] = maax;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);

        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return topdown(1,n-2,nums,dp);
    }
};