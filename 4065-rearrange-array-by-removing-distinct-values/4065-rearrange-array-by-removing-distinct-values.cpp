class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        queue<pair<int,int>> q;
        for(auto x : mp){
            q.push({x.first,x.second});
        }
        vector<int> ans;
        while(!q.empty()){
           auto x = q.front();
           q.pop();
           ans.push_back(x.first);
           if(--x.second > 0){
            q.push({x.first,x.second});
           }
        }
        return ans;
    }
};