class Solution {
public:
    int topdown(int i,int j,vector<vector<int>> &dp,vector<int> &pre){
        if(i >= j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int val = max(pre[j+1]-pre[i+1]-topdown(i+1,j,dp,pre),pre[j]-pre[i]-topdown(i,j-1,dp,pre));
        return dp[i][j] = val;
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i] = pre[i-1] + stones[i-1];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return topdown(0,n-1,dp,pre);
    }
};