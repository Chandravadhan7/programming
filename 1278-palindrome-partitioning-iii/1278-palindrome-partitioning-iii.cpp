class Solution {
public:
    int topdown(int i,int k,vector<vector<int>> &dp,vector<vector<int>> &palin){
        int n = dp.size();
        if(i == n){
           return 0;
        }
        if(k == 0){
            return 1e9;
        }
        
        if(dp[i][k] != -1){
            return dp[i][k];
        }

        int ans = 1e9;
        for(int j=i;j<n;j++){
            if(n-j-1 < k-1) continue;
            ans = min(ans,palin[i][j]+topdown(j+1,k-1,dp,palin));
        }
        return dp[i][k] = ans;
    }
    int palindromePartition(string s, int k) {
        int n = s.length();
        vector<vector<int>> palin(n,vector<int>(n,0));

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i == j){
                    palin[i][j] = 0;
                }else{
                    if(s[i] == s[j]){
                        palin[i][j] = palin[i+1][j-1];
                    }else{
                        palin[i][j] = palin[i+1][j-1] + 1;
                    }
                }
            }
        }

        vector<vector<int>> dp(n,vector<int>(k+1,-1));

        return topdown(0,k,dp,palin);
    }
};