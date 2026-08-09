class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    dp[i][j] = 1;
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }

        int l = 1,r = min(m,n);
        int ans=0;

        while(l <= r){
            int mid = l + (r-l)/2;
            int x1=m,y1=n,x2=-1,y2=-1;

            for(int i=mid-1;i<m;i++){
                for(int j=mid-1;j<n;j++){
                    if(dp[i][j] >= mid){
                       if(i < x1) x1 = i;
                       if(i > x2) x2 = i;
                       if(j < y1) y1 = j;
                       if(j > y2) y2 = j;
                    }
                }
            }

            

            if(x2 != -1 && (x2-x1 >= mid || y2-y1>=mid)){
               ans = mid;
               l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans*ans;
    }
};