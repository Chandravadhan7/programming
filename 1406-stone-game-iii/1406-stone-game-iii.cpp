class Solution {
public:
    int topdown(int i,vector<int> &dp,vector<int> &stoneValue){
        if(i == dp.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int maax = INT_MIN;
        int curr = 0;
        for(int j=i;j<=i+2 && j < dp.size();j++){
            curr += stoneValue[j];
           maax = max(maax,curr-topdown(j+1,dp,stoneValue));
        }

        return dp[i] = maax;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n,-1);

        if(topdown(0,dp,stoneValue) > 0){
           return "Alice";
        }else if(topdown(0,dp,stoneValue) < 0){
            return "Bob";
        }else{
            return "Tie";
        }
    }
};