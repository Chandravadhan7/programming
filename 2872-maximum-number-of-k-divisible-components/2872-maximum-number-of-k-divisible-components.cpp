class Solution {
public:
    int ans = 0;
    long long dfs(int start,int parent,vector<vector<int>> &adj,vector<int> &values,int k){
        long long sum = values[start];
        for(auto child:adj[start]){
            if(child == parent) continue;
            sum += dfs(child,start,adj,values,k);
        }
        if(sum%k == 0){
            ans++;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0,-1,adj,values,k);
        return ans;
    }
};