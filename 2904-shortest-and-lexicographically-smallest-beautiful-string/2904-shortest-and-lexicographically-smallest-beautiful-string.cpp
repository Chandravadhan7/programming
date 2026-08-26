class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        unordered_map<int,int> mp;
        int l = 0;
        int start = -1;
        int len = INT_MAX;

        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp['1'] > k){
                mp[s[l]]--;
                l++;
            }
            while(mp['1'] == k && s[l] == '0'){
                l++;
            }
            
            if(mp['1'] == k){
                if(len > i-l+1){
                    len = i-l+1;
                    start = l;
                }else if(len == i-l+1){
                    if(s.substr(start,len) > s.substr(l,i-l+1)){
                        start = l;
                    }
                }
            }
        }
        if(len ==INT_MAX){
            return "";
        }
        return s.substr(start,len);
    }
};