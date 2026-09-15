class Solution {
public:
    int topdown(int i,vector<vector<int>> &palin,vector<int> &dp,int k){
        int n = dp.size();
        if(n-i < k){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int ans = 0;
        ans = max(ans,topdown(i+1,palin,dp,k));
        for(int j=i+k-1;j<n;j++){
            if(palin[i][j]){
                ans = max(ans,1+topdown(j+1,palin,dp,k));
            }
        }
        return dp[i] = ans;
    }
    int maxPalindromes(string s, int k) {
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

        vector<int> dp(n,-1);

        return topdown(0,palin,dp,k);
    }
};