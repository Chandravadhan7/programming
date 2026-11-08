class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n=s1.length();
        vector<int> same;
        for(int i=0;i<n;i++){
            if(s1[i] == s2[i]){
                same.push_back(i);
            }
        }
        int m = same.size();
        vector<vector<string>> ans;
         if(m == 0) {
            ans.push_back({s1, s2});
            return ans;
        }
        if(s1[0] != s2[0]){
            ans.push_back({s1.substr(0,same[0]),s2.substr(0,same[0])});
        }
        for(int i=1;i<same.size();i++){
            if(same[i]-same[i-1] > 1){
                ans.push_back({s1.substr(same[i-1]+1,same[i]-same[i-1]-1),s2.substr(same[i-1]+1,same[i]-same[i-1]-1)});
            }
        }
        if(s1[n-1] != s2[n-1]){
            ans.push_back({s1.substr(same[m-1]+1,n-same[m-1]-1),s2.substr(same[m-1]+1,n-same[m-1]-1)});
        }
        return ans;
    }
};