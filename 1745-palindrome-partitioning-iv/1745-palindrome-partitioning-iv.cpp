class Solution {
public:
    bool topdown(int i,int k,vector<vector<int>> &dp,vector<vector<int>> &palin){
        int n = dp.size();
        if(i == n){
           if(k == 0){
            return true;
           }else{
            return false;
           }
        }
        if(k == 0){
            return false;
        }

        if(dp[i][k] != -1){
            return dp[i][k];
        }
        
        bool ans = false;
        for(int j=i;j<n;j++){
            if(palin[i][j]){
                if(n-j-1 < k-1) continue;
                ans = ans || topdown(j+1,k-1,dp,palin);
            }
        }
        return dp[i][k] = ans;
    }
    bool checkPartitioning(string s) {
        int n = s.length();
        vector<vector<int>> palin(n,vector<int>(n,0));

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i] == s[j]){
                    if(j-i <= 1){
                        palin[i][j] = 1;
                    }else if(palin[i+1][j-1]){
                        palin[i][j] = 1;
                    }
                }
            }
        }

        vector<vector<int>> dp(n,vector<int>(4,-1));

        return topdown(0,3,dp,palin);
    }
};