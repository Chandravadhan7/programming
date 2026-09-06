class Solution {
public:
    void backtrack(vector<vector<int>> &res,vector<int> &curr,int target,int start,vector<int> &candidates){
        if(target == 0){
            res.push_back(curr);
            return;
        }

        
        for(int i=start;i<candidates.size();i++){
            if(i > start && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] <= target){
                curr.push_back(candidates[i]);
                backtrack(res,curr,target-candidates[i],i+1,candidates);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());

        backtrack(res,curr,target,0,candidates);

        return res;
    }
};