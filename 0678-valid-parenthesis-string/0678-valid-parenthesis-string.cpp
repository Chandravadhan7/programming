class Solution {
public:
    bool topdown(int i,int open,string &s,vector<vector<int>> &dp){
        if(i == s.length()){
            if(open == 0){
                return true;
            }else{
                return false;
            }
        }

        if(dp[i][open] != -1){
            return dp[i][open];
        }
        
        bool ans = false;
        if(s[i] == '('){
           ans |= topdown(i+1,open+1,s,dp);
        }else if(s[i] == '*'){
            ans |= topdown(i+1,open+1,s,dp);
            ans |= topdown(i+1,open,s,dp);

            if(open > 0){
                ans |= topdown(i+1,open-1,s,dp);
            }
        }else{
            if(open > 0){
                ans |= topdown(i+1,open-1,s,dp);
            }
        }
        return dp[i][open] = ans;
    }
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return topdown(0,0,s,dp);
    }
};