class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int maax = 0;
        int l = 0;
        unordered_map<char,int> mp;

        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp[s[i]] > 2){
                mp[s[l]]--;
                l++;
            }

            maax = max(maax,i-l+1);
        }
        return maax;
    }
};