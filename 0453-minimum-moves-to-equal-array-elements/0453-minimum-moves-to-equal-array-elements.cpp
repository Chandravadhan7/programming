class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        int minn = nums[0];
        for(int i=0;i<n;i++){
            ans += nums[i]-minn;
        }

        return ans;
    }
};