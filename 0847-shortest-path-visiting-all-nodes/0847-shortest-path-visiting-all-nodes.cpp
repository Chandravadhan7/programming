class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int mask = (1 << n)-1;
        vector<vector<int>> vis(n,vector<int>(mask+1,false));

        queue<tuple<int,int,int>> q;
        for(int i=0;i<n;i++){
            q.push({i,0,1<<i});
            vis[i][1<<i] = true;
        }

        while(!q.empty()){
            auto [u,d,m] = q.front();
            q.pop();

            if(m == mask){
                return d;
            }

            for(auto x:graph[u]){
                int k = m | (1<<x);
                if(!vis[x][k]){
                    vis[x][k] = 1;
                    q.push({x,d+1,k});
                }

            }
        }
        return -1;
    }
};