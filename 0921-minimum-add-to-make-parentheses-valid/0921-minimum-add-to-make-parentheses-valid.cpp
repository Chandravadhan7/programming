class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        stack<char> st;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    ans++;
                }
            }
        }
        ans += st.size();

        return ans;
    }
};