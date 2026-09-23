class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,long long> mp;
        long long ans = 0;
        int l = 0;
        long long count = 0;
        for(int i=0;i<n;i++){
            
            count += mp[nums[i]];
            mp[nums[i]]++;
            while(count >= k){
                ans += (n-i);
                mp[nums[l]]--;

                count -= mp[nums[l]];
                l++;
            }
        }
        return ans;
    }
};