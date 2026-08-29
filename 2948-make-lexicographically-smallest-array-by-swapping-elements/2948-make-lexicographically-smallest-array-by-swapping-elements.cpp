class Solution {
public:
    vector<int> parent,rank;
    int find(int u){
        if(u != parent[u]){
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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        parent.resize(n);
        rank.assign(n,0);
        vector<vector<int>> temp;

        for(int i=0;i<n;i++){
            parent[i] = i;
            temp.push_back({nums[i],i});
        }

        sort(temp.begin(),temp.end());

        for(int i=1;i<n;i++){
            int val = temp[i][0];
            int idx = temp[i][1];
            if(abs(val-temp[i-1][0]) <= limit){
                unite(temp[i-1][1],idx);
            }
        }

        for(int i=0;i<n;i++){
            parent[i] = find(i);
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[parent[i]].push_back(i);
        }

        for(auto x : mp){
            vector<int> temp;
            for(auto e : x.second){
                temp.push_back(nums[e]);
            }
            sort(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++){
                nums[x.second[i]] = temp[i];
            }
        }
        
        return nums;

    }
};