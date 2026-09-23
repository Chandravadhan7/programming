class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int rem = sum-x;
        if(rem < 0){
            return -1;
        }
        if(rem == 0){
            return n;
        }
        int curr = 0;
        int mx = -1;
        int l = 0;
        for(int i=0;i<n;i++){
            curr += nums[i];
            while(curr > rem){
                curr -= nums[l];
                l++;
            }
            if(curr == rem){
                mx = max(mx,i-l+1);
            }
        }
        if(mx == -1){
            return -1;
        }
        return n-mx;
    }
};