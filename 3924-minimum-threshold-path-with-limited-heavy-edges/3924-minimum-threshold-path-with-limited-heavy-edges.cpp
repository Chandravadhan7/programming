class Solution {
public:
    bool dfs(int n,vector<vector<pair<int,int>>> &adj,int source,int target,int k,int mid){
       vector<int> heavy(n,INT_MAX);
       queue<pair<int,int>> q;
       heavy[source] = 0;
       q.push({source,0});

       while(!q.empty()){
           auto x = q.front();
           q.pop();

        //    if(x.second > heavy[x.first] || x.second > k){
        //      continue;
        //    }

           for(auto [v,e] : adj[x.first]){
              int newload;
              if(e > mid){
                newload = min(heavy[v],heavy[x.first]+1);
              }else{
                newload = heavy[x.first];
              }
              if(newload < heavy[v] && newload <= k){
                heavy[v] = newload;
                q.push({v,heavy[v]});
              }
           }
       }

       return heavy[target]<=k;

    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        int l = 0,r = 1e9;

        int ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(dfs(n,adj,source,target,k,mid)){
               ans = mid;
               r = mid - 1;
            }else{
               l = mid + 1;
            }
        }

        return ans;
    }
};