class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int,pair<int,int>> mp;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[mat[i][j]] = make_pair(i,j);
            }
        }

        vector<int> row(m,0),col(n,0);

        for(int i=0;i<arr.size();i++){
            int x = mp[arr[i]].first;
            int y = mp[arr[i]].second;

            row[x]++;
            col[y]++;
            
            // if(row[x] == n && col[y] == m){
            //     return min(x+1,y+1);
            // }
            if(row[x] == n){
                return i;
            }
            if(col[y] == m){
                return i;
            }
        }
       return 0;
    }
};