class Solution {
public:
    vector<int> parent,rank;
    int find(int u){
        if(parent[u] != u){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void unite(int u,int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv){
            return;
        }

        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int N = m*n;
        parent.resize(N);
        rank.assign(N,0);

        for(int i=0;i<N;i++){
            parent[i] = i;
        }
        
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        vector<vector<int>> row(m),col(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    row[i].push_back(i*n+j);
                    col[j].push_back(i*n+j);
                }
            }
        }
        for(int i=0;i<m;i++){
            if(row[i].size() > 1){
                for(int j=0;j<row[i].size()-1;j++){
                    unite(row[i][j],row[i][j+1]);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(col[i].size() > 1){
                for(int j=0;j<col[i].size()-1;j++){
                    unite(col[i][j],col[i][j+1]);
                }
            }
        }
        unordered_map<int,int> mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[find(i*n+j)]++;
            }
        }
        int ans = 0;
        for(auto x : mp){
            if(x.second > 1){
                ans += x.second;
            }
        }
        return ans;

        
    }
};