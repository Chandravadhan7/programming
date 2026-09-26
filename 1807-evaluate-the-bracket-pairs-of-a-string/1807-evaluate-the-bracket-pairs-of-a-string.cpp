class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        map<string,string> mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        int r = s.find(')');
        while(r != string::npos){
            int l = s.rfind('(',r);
            string str = s.substr(l+1,r-l-1);
            if(mp.count(str)){
                s.replace(l,r-l+1,mp[str]);
            }else{
                s.replace(l,r-l+1,"?");
            }
            r = s.find(')');
        }
        return s;
    }
};