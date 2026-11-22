class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& req) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x : edges){
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<long long> res(n,-1);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;

        res[0] = 0;

        for (auto& [v, d] : adj[0]) {
            pq.emplace(d, v);
        }

        while(!pq.empty()){
            auto [t,u] = pq.top();
            pq.pop();

            if(res[u] >= 0) continue;

            if(--req[u] == 0){
               res[u] = t;
               for(auto [v,d] : adj[u]){
                pq.push({t+d,v});
               }
            }
        }
        return res;
    }
};