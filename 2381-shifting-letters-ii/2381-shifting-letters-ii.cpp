class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();

        vector<int> diff(n+1,0);

        for(auto x : shifts){
            int start = x[0];
            int end = x[1];
            int dir = x[2];
            
            if(dir == 0){
                dir = -1;
            }

            diff[start] += dir;
            diff[end+1] -= dir;
        }

        for(int i=1;i<n;i++){
           diff[i] += diff[i-1];
        }
        
        for(int i=0;i<n;i++){
            if(diff[i] == 0) continue;

            int id = s[i] - 'a';
            int temp = (((id+diff[i])%26)+26)%26;
            s[i] = char(temp + 'a');
        }
        return s;
    }
};