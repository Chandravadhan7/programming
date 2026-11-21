class Solution {
public:
    vector<int> p;
    void dfs(int start,vector<vector<int>> &adj,string &s,vector<int> lastocc){
        int id = s[start] - 'a';
        if(lastocc[id] != -1){
            p[start] = lastocc[id];
        }
        lastocc[id] = start;
        for(auto x : adj[start]){
            dfs(x,adj,s,lastocc);
        }
    }
    int calSize(int s,vector<vector<int>> &a,vector<int> &ans){
        int size = 1;
        for(auto x : a[s]){
            size += calSize(x,a,ans);
        }
        ans[s] = size;
        return size;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.length();
        vector<int> lastocc(26,-1);
        vector<vector<int>> adj(n);
        p = parent;
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        dfs(0,adj,s,lastocc);
        vector<int> ans(n);
        vector<vector<int>> a(n);
        for(int i=1;i<n;i++){
            a[p[i]].push_back(i);
        }
        calSize(0,a,ans);
        
        return ans;
    }
};