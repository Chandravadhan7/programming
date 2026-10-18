class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(),nums.end());

        int count = 0;
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                count++;
            }
        }
        return count;
    }
};