class Solution {
public:
    int topdown(int r,int prev,vector<vector<int>> &dp,vector<vector<char>> &seats){
        int n = seats.size();
        int m = seats[0].size();
        if(r >= n){
            return 0;
        }

        if(dp[r][prev] != -1){
            return dp[r][prev];
        }
        dp[r][prev] = 0;
        for(int curr=0;curr<(1<<m);curr++){
            string bin = bitset<32>(curr).to_string();
            bin = bin.substr(32-m);
            bool adj = true;
            for(int i=0;i<m;i++){
                if(bin[i] == '1' && seats[r][i] == '#'){
                    adj = false;
                    break;
                }
            }
            for(int i=1;i<m;i++){
                if(bin[i] == '1'){
                    if(bin[i] == bin[i-1]){
                        adj = false;
                        break;
                    }
                }
            }
            if(adj && ((prev << 1) & curr) == 0 && ((prev>>1)&curr) == 0){
                dp[r][prev] = max(dp[r][prev],__builtin_popcount(curr)+topdown(r+1,curr,dp,seats));
            }
        }
        return dp[r][prev];
    }
    
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();

        vector<vector<int>> dp(m,vector<int>(1<<n,-1));
        return topdown(0,0,dp,seats);
    }
};