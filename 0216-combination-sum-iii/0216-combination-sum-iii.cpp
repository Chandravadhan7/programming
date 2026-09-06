class Solution {
public:
    void helper(int num,int k,int n,vector<vector<int>> &res,vector<int> &curr){
        if(n == 0 && curr.size() == k){
           res.push_back(curr);
           return;
        }

       if(num <= 9){
        helper(num+1,k,n,res,curr);

        if(num <= n){
            curr.push_back(num);
            helper(num+1,k,n-num,res,curr);
            curr.pop_back();
        }
       }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(1,k,n,res,curr);
        return res;
    }
};