class Solution {
public:
    int intersect(vector<int> a,vector<int> b){
        int n = a.size();
        int i=0,j=0;
        int count = 0;

        while(i<n && j<n){
            if(a[i] == b[j]){
                count++;
                int val = a[i];
                while(i<n && a[i] == val){
                    i++;
                }
                while(j<n && b[j] == val){
                    j++;
                }
            }else if(a[i] > b[j]){
                j++;
            }else{
                i++;
            }
        }
        return count;
    }

   void dfs(int idx, vector<vector<int>>& edges, vector<int>& visited) {
      visited[idx] = 1;
      for (int x : edges[idx]) {
          if (visited[x] == 0) {
            dfs(x, edges, visited);
           }
       }
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<int> visited(n,0);
        vector<vector<int>> edges(n);
        for(auto &x : properties){
            sort(x.begin(),x.end());
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(intersect(properties[i],properties[j]) >= k){
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
         int sum = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                sum++;
                dfs(i, edges, visited);
            }
        }
        return sum;
    }
};