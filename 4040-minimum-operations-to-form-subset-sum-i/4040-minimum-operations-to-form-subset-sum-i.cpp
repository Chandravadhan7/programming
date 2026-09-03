class Solution {
public:
    int topdown(int i,int j,vector<vector<pair<int,int>>> &options,vector<vector<int>> &dp){
        if(j == 0){
            return 0;
        }

        if(i == dp.size()){
            return INT_MAX;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = topdown(i+1,j,options,dp);

        for(auto x : options[i]){
            if(x.first <= j && topdown(i+1,j-x.first,options,dp) != INT_MAX){
                ans = min(ans,x.second+topdown(i+1,j-x.first,options,dp));
            }
        }
        return dp[i][j] = ans;
    }
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<pair<int,int>>> options(n);
        
        for(int i=0;i<n;i++){
            int val = nums[i];
            int count = 0;

            while(val <= sum){
                options[i].push_back({val,count});

                val = val*2;
                count++;
            }

            val = nums[i];
            count = 0;

            while(val > 0){
                options[i].push_back({val,count});

                val = val/2;
                count++;
            }
        }

        vector<vector<int>> dp(n,vector<int>(sum+1,-1));

        return topdown(0,sum,options,dp)==INT_MAX?-1:topdown(0,sum,options,dp);
    }
};