class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int zero = 0;

        for(int i=0;i<n;i++){
            total ^= nums[i];
            if(nums[i] > 0){
                zero = 1;
            }
        }

        if(total > 0){
            return n;
        }
        return zero?n-1:0;
    }
};