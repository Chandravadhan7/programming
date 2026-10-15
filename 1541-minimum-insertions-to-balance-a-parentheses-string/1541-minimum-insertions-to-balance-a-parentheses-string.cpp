class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        stack<char> st;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(i<n-1 && s[i+1] == ')'){
                    if(!st.empty() && st.top() == '('){
                        st.pop();
                    }else{
                        ans += 1;
                    }
                    i++;
                }else{
                    if(!st.empty() && st.top() == '('){
                        ans += 1;
                        st.pop();
                    }else{
                        ans += 2;
                    }
                }
            }
        }
        ans += 2*st.size();
        return ans;
    }
};