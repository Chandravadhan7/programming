class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(auto x : paths){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> color(n,0);
        for(int i=1;i<=n;i++){
            if(color[i-1] != 0) continue;
            queue<int> q;
            q.push(i);
            color[i-1] = 1;
            while(!q.empty()){
                auto x = q.front();
                q.pop();

                for(auto a : adj[x]){
                    if(color[a-1] != 0) continue;
                    vector<int> k(4,0);
                    for(auto v : adj[a]){
                        if(color[v-1] != 0){
                            k[color[v-1]-1] = 1;
                        }
                    }
                    for(int c=0;c<4;c++){
                        if(k[c] == 0){
                            color[a-1] = c+1;
                            q.push(a);
                            break;
                        }
                    }
                }
            }
        }
        return color;
    }
};