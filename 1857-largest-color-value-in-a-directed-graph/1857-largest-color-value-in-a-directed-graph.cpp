class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);

        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        vector<vector<int>> dp(n,vector<int>(26,0));
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                dp[i][colors[i]-'a'] = 1;
            }
        }

        int ans = 0;
        int count = 0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            count++;

            for(auto a : adj[x]){
                for(int c=0;c<26;c++){
                    dp[a][c] = max(dp[a][c],dp[x][c] + (c == colors[a]-'a'?1:0));
                }

                if(--indegree[a] == 0){
                    q.push(a);
                }
            }
        }
        if(count != n){
            return -1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};