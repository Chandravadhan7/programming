class Solution {
public:
    int topdown(int i,int m,vector<vector<int>> &dp,vector<int> &piles){
        if(i >= dp.size()){
            return 0;
        }
        if(dp[i][m] != -1){
            return dp[i][m];
        }
        
        int maax = INT_MIN;
        int curr = 0;
        for(int j=i;j<min((int)dp.size(),i+(2*m));j++){
            curr += piles[j];

            maax = max(maax,curr-topdown(j+1,max(m,j+1-i),dp,piles));
        }

        return dp[i][m] = maax;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int sum = accumulate(piles.begin(),piles.end(),0);

        return (sum + topdown(0,1,dp,piles))/2;
    }
};