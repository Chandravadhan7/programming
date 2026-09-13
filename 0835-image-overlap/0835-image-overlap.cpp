class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> p1,p2;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j] == 1){
                    p1.push_back({i,j});
                }
                if(img2[i][j] == 1){
                    p2.push_back({i,j});
                }
            }
        }

        int mx = 2*n-2;
        map<pair<int,int>,int> mp;
        int ans = 0;

        for(auto x : p1){
            for(auto y : p2){
                int dx = y.first-x.first+n;
                int dy = y.second-x.second+n;

                // if(dx > mx || dy > mx) continue;

                mp[{dx,dy}]++;
                ans = max(ans,mp[{dx,dy}]);
            }
        }
        return ans;
    }
};