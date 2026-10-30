class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x : edges){
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<vector<int>> dist(n,vector<int>(k+1,INT_MAX));
        dist[0][1] = 0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;

        pq.push({0,0,1});

        while(!pq.empty()){
            auto [d,u,f] = pq.top();
            pq.pop();

            if(dist[u][f] < d) continue;

            for(auto [v,e] : adj[u]){
                if(labels[v] != labels[u]){
                    if(dist[v][1] > d + e){
                        dist[v][1] = d + e;
                        pq.push({dist[v][1],v,1});
                    }
                }else{
                    if(f+1 > k) continue;
                    if(dist[v][f+1] > d + e){
                        dist[v][f+1] = d + e;
                        pq.push({dist[v][f+1],v,f+1});
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(int f=0;f<=k;f++){
            ans = min(ans,dist[n-1][f]);
        }
        return ans==INT_MAX?-1:ans;
    }
};