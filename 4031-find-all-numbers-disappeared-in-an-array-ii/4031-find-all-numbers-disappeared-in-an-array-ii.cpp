class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
       int n =  nums.size();
       sort(nums.begin(),nums.end());
       vector<int> vis(upper+1,0);
       for(int i=0;i<n && nums[i]<=upper;i++){
        vis[nums[i]] = 1;
       }
       int left = lower;
       vector<vector<int>> ans;

       for(int i=lower;i<=upper;i++){
          if(vis[i]){
            if(left == i){
                left = i+1;
                continue;
            }else{
                ans.push_back({left,i-1});
                left = i+1;
            }
          }
       }
       if(left <= upper){
       ans.push_back({left,upper});
       }
       return ans;

    }
};