class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> lis;
        for(int i=0;i<n;i++){
            if(lis.empty() || lis.back() <= nums[i]){
               lis.push_back(nums[i]);
               ans[i] = lis.size();
            }else{
                int id = upper_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                lis[id] = nums[i];
                ans[i] = id+1;
            }
        }
        return ans;
    }
};