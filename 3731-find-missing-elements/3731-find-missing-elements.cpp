class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int maax = *max_element(nums.begin(),nums.end());
        int miin = *min_element(nums.begin(),nums.end());

        set<int> st(nums.begin(),nums.end());

        vector<int> ans;

        for(int i=miin;i<=maax;i++){
           if(!st.count(i)){
            ans.push_back(i);
           }
        }

        return ans;
    }
};