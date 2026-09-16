class Solution {
public:
    int mod = 1e9+7;
    int topdown(int i,int k,int n,vector<vector<int>> &dp){
        if(k == 0){
            return 1;
        }
        if(i >= n){
            return 0;
        }

        

        if(dp[i][k] != -1){
            return dp[i][k];
        }
        
        int ans = 0;
        if(n-i >= k+1){
          ans = (ans+topdown(i+1,k,n,dp))%mod;
        }

        for(int j=i+1;j<n;j++){
            if(n-j >= k){
                ans = (ans+topdown(j,k-1,n,dp))%mod;
            }
        }
        return dp[i][k] = ans;
    }
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));

        return topdown(0,k,n,dp);
    }
};