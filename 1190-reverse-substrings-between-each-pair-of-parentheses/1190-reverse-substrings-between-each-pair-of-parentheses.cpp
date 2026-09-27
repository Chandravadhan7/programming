class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        int r = s.find(')');
        while(r != string::npos){
            int l = s.rfind('(',r);
            string str = s.substr(l+1,r-l-1);
            reverse(str.begin(),str.end());
            s.replace(l,r-l+1,str);
            r = s.find(')');
        }
        return s;

    }
};