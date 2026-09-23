class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pre(n,0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }

        int idx = lower_bound(pre.begin(),pre.end(),x)-pre.begin();

        if(idx == n) return -1;
        int ans = INT_MAX;;
        if(pre[idx] == x){
            ans = idx+1;
        }

        for(int i=n-1;i>=0;i--){
            x -= nums[i];
            if(x < 0){
                break;
            }
            if(x == 0){
                ans = min(ans,n-i);
            }

            int idx = lower_bound(pre.begin(),pre.end(),x)-pre.begin();
            if(idx < i && pre[idx] == x){
                ans = min(ans,idx+1+n-i);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};