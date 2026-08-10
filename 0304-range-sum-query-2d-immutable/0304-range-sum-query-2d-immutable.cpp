class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        mat = matrix;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i > 0){
                    mat[i][j] += mat[i-1][j];
                }
                if(j > 0){
                    mat[i][j] += mat[i][j-1];
                }

                if(i > 0 && j > 0){
                    mat[i][j] -= mat[i-1][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       int ans = mat[row2][col2];

       if(row1 > 0){
        ans -= mat[row1-1][col2];
       }
       if(col1 > 0){
        ans -= mat[row2][col1-1];
       }
       if(row1 > 0 && col1 > 0){
        ans += mat[row1-1][col1-1];
       }
       return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */