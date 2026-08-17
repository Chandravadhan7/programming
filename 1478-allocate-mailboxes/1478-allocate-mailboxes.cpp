class Solution {
public:
    int topdown(int i,int k,vector<vector<int>> &dp,vector<vector<int>> &cost){
        int n = dp.size();
        if(k == 0 && i == n) return 0;
        if(k == 0 || i == n) return 1e6;
        if(dp[i][k] != -1){
            return dp[i][k];
        }

        int ans = INT_MAX;
        for(int j=i;j<dp.size();j++){
            ans = min(ans,cost[i][j]+topdown(j+1,k-1,dp,cost));
        }
        return dp[i][k] = ans;
    }
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(),houses.end());
        vector<vector<int>> cost(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int median = houses[(i+j)/2];
                for(int k=i;k<=j;k++){
                    cost[i][j] += abs(median-houses[k]);
                }
            }
        }
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return topdown(0,k,dp,cost);
    }
};