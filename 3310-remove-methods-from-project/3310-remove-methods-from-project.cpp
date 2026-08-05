class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto x : invocations){
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
        }

        vector<int> suspicious(n,0);

        queue<int> q;

        q.push(k);
        suspicious[k] = 1;

        while(!q.empty()){
            auto x = q.front();
            q.pop();

            for(auto a : adj[x]){
                if(suspicious[a]) continue;
                q.push(a);
                suspicious[a] = 1;
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!suspicious[i]){
                q.push(i);
                ans.push_back(i);
            }
        }

        vector<int> vis(n,0);
        
        bool canRemove = true;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(vis[x]) continue;
            vis[x] = 1;

            for(auto a : adj[x]){
                if(suspicious[a]){
                    canRemove = false;
                    break;
                }else if(!vis[a]){
                    q.push(a);
                }
            }
        }

        if(!canRemove){
            for(int i=0;i<n;i++){
                if(suspicious[i]){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};