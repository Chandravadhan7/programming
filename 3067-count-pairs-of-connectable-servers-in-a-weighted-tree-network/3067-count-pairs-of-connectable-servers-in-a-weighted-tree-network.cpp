class Solution {
public:
    void dfs(int start,int dist,vector<vector<pair<int,int>>> &adj,vector<int> &vis,int signalSpeed,int &c){
        if(dist%signalSpeed == 0){
           c++;
        }
        vis[start] = 1;
        for(auto x : adj[start]){
            if(!vis[x.first]){
                dfs(x.first,dist+x.second,adj,vis,signalSpeed,c);
            }
        }
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size();
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto x : edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++){
            vector<int> temp;
            for(auto x : adj[i]){
                vector<int> vis(n+1,0);
                vis[i] = 1;
                int count = 0;
                dfs(x.first,x.second,adj,vis,signalSpeed,count);
                temp.push_back(count);
            }
            for(int k=0;k<temp.size();k++){
                for(int j=k+1;j<temp.size();j++){
                    ans[i] += (temp[k]*temp[j]);
                }
            }
        }
        return ans;
    }
};