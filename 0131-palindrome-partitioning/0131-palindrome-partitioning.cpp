class Solution {
public:
    bool isPalindrome(int i,int j,string s){
        while(i <= j && s[i] == s[j]){
            i++;
            j--;
        }

        return i >= j;
    }
    void helper(int i,vector<vector<string>> &res,string &s,vector<string> &curr){
        if(i == s.length()){
          res.push_back(curr);
          return;
        }

        for(int j=i;j<s.length();j++){
            if(isPalindrome(i,j,s)){
                curr.push_back(s.substr(i,j-i+1));
                helper(j+1,res,s,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> res;
        vector<string> curr;
        helper(0,res,s,curr);
        return res;
    }
};