class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(),nums.end());
        
        int mul = 1;
        while(st.count(k*mul)){
            mul++;
        }
        return k*mul;
    }
};