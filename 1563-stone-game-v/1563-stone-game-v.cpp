class Solution {
public:
    int topdown(int i,int j,vector<vector<int>> &dp,vector<int> &pre){
        if(i == j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        for(int k=i;k<j;k++){
            int left = pre[k];
            if(i > 0){
                left -= pre[i-1];
            }
            int right = pre[j] - pre[k];

            if(left < right){
                ans = max(ans,left+topdown(i,k,dp,pre));
            }else if(right < left){
                ans = max(ans,right+topdown(k+1,j,dp,pre));
            }else{
                ans = max(ans,left+topdown(i,k,dp,pre));
                ans = max(ans,right+topdown(k+1,j,dp,pre));
            }
        }
        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> pre(n,0);
        pre[0] = stoneValue[0];

        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + stoneValue[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return topdown(0,n-1,dp,pre);

    }
};