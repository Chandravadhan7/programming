class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x : redEdges){
            adj[x[0]].push_back({x[1],1});
        }
        for(auto x : blueEdges){
            adj[x[0]].push_back({x[1],2});
        }

        queue<vector<int>> q;
        vector<vector<int>> dist(n,vector<int>(3,INT_MAX));
        dist[0][0] = 0;
        q.push({0,0,0});

        vector<int> ans(n);

        while(!q.empty()){
            auto x = q.front();
            q.pop();
            

            for(auto [v,cl] : adj[x[0]]){
                if(cl != x[2] && dist[v][cl] == INT_MAX){
                    dist[v][cl] = x[1] + 1;
                    q.push({v,dist[v][cl],cl});
                }
            }
        }
        ans[0] = 0;
        for(int i=1;i<n;i++){
            ans[i] = min(dist[i][1],dist[i][2]);
            if(ans[i] == INT_MAX){
                ans[i] = -1;
            }
        }
        return ans;
    }
};