class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int N = n*m;

        vector<int> temp(N);

        k = k%N;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int id = i*m+j;
                temp[id] = grid[i][j];
            }
        }

        reverse(temp.begin(),temp.end());
        reverse(temp.begin(),temp.begin()+k);

        reverse(temp.begin()+k,temp.end());

        vector<vector<int>> ans(n,vector<int>(m));

        for(int id=0;id<N;id++){
            int i = id/m;
            int j = id%m;
            grid[i][j] = temp[id];
        }
        return grid;
    }
};