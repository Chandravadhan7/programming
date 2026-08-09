class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        int mx = *max_element(parent.begin(),parent.end());

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(parent[i] >= 0 && parent[i] < n){
                adj[parent[i]].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        q.push({0,1});
        vector<int> vis(n,0);
        vis[0] = 1;

        long long ans = 0;
        vector<pair<int,int>> temp;

        int maax = 0;

        while(!q.empty()){
            auto [u,d] = q.front();
            q.pop();
            
            temp.push_back({nums[u],d});
            maax = max(maax,d);

            for(auto x : adj[u]){
                if(!vis[x]){
                   q.push({x,d+1});
                   vis[x] = 1;
                }
            }

        }

        for(auto x : temp){
            int val = x.first;
            int d = x.second;

            ans += 1LL*val*(maax-d+1);
        }

        return ans;

    }
};