class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int pro = 1;
        int l = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            pro *= nums[i];
            while(l <= i && pro >= k){
                pro = pro/nums[l];
                l++;
            }
            ans += (i-l+1);
        }
        return ans;
    }
};