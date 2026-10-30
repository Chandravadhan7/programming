class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size();
        int n = values[0].size();
        vector<int> arr;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr.push_back(values[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int day = 1;
        long long ans = 0;
        for(int i=0;i<(m*n);i++){
            ans += 1LL*day*arr[i];
            day++;
        }

        return ans;
    }
};