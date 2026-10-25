class Solution {
public:
    void bfs(int start,vector<int> &color,vector<vector<int>> &adj){
        color[start-1] = 1;
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            auto x = q.front();
            q.pop();
            
           
            for(auto v : adj[x]){
                if(color[v-1] != -1) continue;
                vector<int> taken(5,0);
                for(auto a : adj[v]){
                    if(color[a-1] != -1){
                        taken[color[a-1]] = 1;
                    }
                }
                for(int c=1;c<=4;c++){
                    if(taken[c] == 0){
                        color[v-1] = c;
                        q.push(v);
                        break;
                    }
                }
            }
        }

    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(auto x : paths){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> color(n,-1);
        for(int i=1;i<=n;i++){
            if(color[i-1] == -1){
                bfs(i,color,adj);
            }
        }
        return color;

    }
};