class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);

        for(int i=0;i<n;i++){
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
            indegree[edges[i]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> vis(n,0);

        while(!q.empty()){
            auto x = q.front();
            q.pop();

            vis[x] = 1;
            
            for(auto a : adj[x]){
                if(--indegree[a] == 0){
                    q.push(a);
                }
            }
        }

        bool c = false;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                c = true;
                break;
            }
        }
        if(!c){
            return -1;
        }
        
        int maax = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
              int count = 0;
              int start = i;

              while(!vis[start]){
                count++;
                vis[start] = 1;
                start = edges[start];
                
              }
              maax = max(maax,count);
            }
        }
        return maax;
    }
};