class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        if(k == n){
          return *max_element(nums.begin(),nums.end());
        }
        if(k == 1){
            int maax = -1;
            for(auto x : mp){
               if(x.second == 1){
                maax = max(maax,x.first);
               }
            }
            return maax;
        }else{
           if(mp[nums[0]] > 1 && mp[nums[nums.size()-1]] > 1){
            return -1;
           }else if(mp[nums[0]] == 1 && mp[nums[nums.size()-1]] == 1){
            return max(nums[0],nums[nums.size()-1]);
           }else if(mp[nums[0]] == 1 || mp[nums[nums.size()-1]] == 1){
            if(mp[nums[0]] == 1){
                return nums[0];
            }else if(mp[nums[nums.size()-1]] == 1){
                return nums[nums.size()-1];
            }
           }
        }
        return 0;
    }
};