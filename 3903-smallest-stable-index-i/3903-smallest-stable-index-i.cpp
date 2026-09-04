class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n),suff(n);

        pre[0] = nums[0];
        int mx = nums[0];

        for(int i=1;i<n;i++){
           mx = max(mx,nums[i]);
           pre[i] = mx;
        }

        int mn = nums[n-1];
        suff[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--){
            mn = min(mn,nums[i]);
            suff[i] = mn;
        }

        for(int i=0;i<n;i++){
            if(pre[i]-suff[i] <= k){
                return i;
            }
        }

        return -1;
    }
};