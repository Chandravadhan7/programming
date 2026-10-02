class Solution {
public:
    vector<string> res;
    void backtrack(int open,int close,string curr,int n){
        if(open + close == 2*n){
            res.push_back(curr);
            return;
        }
        if(open < n){
            backtrack(open+1,close,curr+'(',n);
        }
        if(close < open){
            backtrack(open,close+1,curr+')',n);
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(0,0,"",n);
        return res;
    }
};