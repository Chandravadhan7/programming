class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i=0;i<n;i++){
            if(i != nums[i]){
                if(ans == -1){
                    ans = nums[i];
                }else{
                    ans = ans & nums[i];
                }                
            }
        }
        return ans;
    }
};