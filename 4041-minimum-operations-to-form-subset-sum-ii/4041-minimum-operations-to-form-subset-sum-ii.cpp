class Solution {
public:
    int topdown(int i,int j,vector<vector<int>> &dp,vector<vector<pair<int,int>>> &choices){
        if(j == 0){
            return 0;
        }
        if(i == dp.size()){
            return INT_MAX;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = topdown(i+1,j,dp,choices);

        for(auto [val,count] : choices[i]){
            if(val <= j && topdown(i+1,j-val,dp,choices) != INT_MAX){
                ans = min(ans,count+topdown(i+1,j-val,dp,choices));
            }
        }

        return dp[i][j] = ans;
    }
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<pair<int,int>>> choices(n);

        for(int i=0;i<n;i++){
            int val = nums[i];
            unordered_set<int> vis;
            queue<pair<int,int>> q;
            q.push({val,0});
            q.push({val/2,1});
            q.push({2*val,1});

            vis.insert(val);
            vis.insert(val/2);
            vis.insert(2*val);

            while(!q.empty()){
                auto [v,count] = q.front();
                q.pop();

                choices[i].push_back({v,count});

                if(2*v <= sum && !vis.count(2*v)){
                    q.push({2*v,count+1});
                    vis.insert(2*v);
                }
                if(v/2 > 0 && !vis.count(v/2)){
                    q.push({v/2,count+1});
                    vis.insert(v/2);
                }
            }
        }

        vector<vector<int>> dp(n,vector<int>(sum+1,-1));

        return topdown(0,sum,dp,choices)==INT_MAX?-1:topdown(0,sum,dp,choices);
    }
};