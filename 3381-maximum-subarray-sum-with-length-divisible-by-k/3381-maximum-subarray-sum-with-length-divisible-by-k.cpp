class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,long long> mp;
        mp[k-1] = 0;
        long long sum = 0;
        long long ans = LLONG_MIN;
        for(int i=0;i<n;i++){
            sum += (long long)nums[i];
            if(mp.count(i%k)){
                ans = max(ans,sum-mp[i%k]);
                mp[i%k] = min(mp[i%k],sum);
            }else{
                mp[i%k] = sum;
            }
        }
        return ans;
    }
};