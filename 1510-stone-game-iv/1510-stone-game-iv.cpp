class Solution {
public:
    bool topdown(vector<int> &dp,int i){
        if(i == 0){
            return false;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        for(int j=1;j*j<=i;j++){
            if(topdown(dp,i-j*j) == false){
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);

        return topdown(dp,n);
    }
};