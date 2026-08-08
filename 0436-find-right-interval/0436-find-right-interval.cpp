class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i=0;i<n;i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end());

        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int l = intervals[i][0];
            int r = intervals[i][1];
            int idx = intervals[i][2];

            int id = lower_bound(intervals.begin(),intervals.end(),vector<int>{r, INT_MIN}) - intervals.begin();

            if(id == n) continue;

            // if(id != 0) id--;
            
            ans[idx] = intervals[id][2];
        }
        return ans;
    }
};