class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        map<vector<int>,int> mp;
        int l = 0;
        int maxx = 0;
        
        for(int i=0;i<n-1;i++){
            if(nums[i] != nums[i+1]){
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[i+1]);
                sort(v.begin(),v.end());
                mp[v]++;
            }else{
                l++;
            }
        }
        for(auto x : mp){
           maxx = max(maxx,x.second);
        }
        return l+maxx;
    }
};