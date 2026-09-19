class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // vector<int> temp = nums;
        // nums[0] = nums[1] = nums[n-1];
        // temp[n-1] = temp[n-2] = temp[0]; 
        // sort(nums.begin(),nums.end());
        // sort(temp.begin(),temp.end());
        return min({nums[n-1]-nums[2],nums[n-3]-nums[0],nums[n-2]-nums[1]});
    }
};