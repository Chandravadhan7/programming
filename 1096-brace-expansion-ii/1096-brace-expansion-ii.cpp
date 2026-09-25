class Solution {
public:
    set<string> st;
    void dfs(string s){
        int r = s.find('}');
        if(r == string::npos){
          st.insert(s);
          return;
        }
        int l = s.rfind('{',r);

        string left = s.substr(0,l);
        string right = s.substr(r+1);

        string str = s.substr(l+1,r-l-1);

        stringstream ss(str);
        string temp;
        while(getline(ss,temp,',')){
            dfs(left+temp+right);
        }
    }
    vector<string> braceExpansionII(string expression) {
        dfs(expression);
        vector<string> ans(st.begin(),st.end());
        return ans;
    }
};