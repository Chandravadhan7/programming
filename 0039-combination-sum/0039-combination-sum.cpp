class Solution {
public:
    void helper(vector<int> &candidates,int i,int target,vector<vector<int>> &res,vector<int> &curr){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        if(target < 0 || i == candidates.size()){
            return;
        }

        helper(candidates,i+1,target,res,curr);

        if(candidates[i] <= target){
            curr.push_back(candidates[i]);
            helper(candidates,i,target-candidates[i],res,curr);
            curr.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        helper(candidates,0,target,res,curr);

        return res;
    }
};