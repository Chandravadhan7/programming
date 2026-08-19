class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>> mp;

        for(auto x : reservedSeats){
            mp[x[0]].insert(x[1]);
        }
        int ans = 0;

        for(auto x : mp){
            auto st = x.second;
        
            bool left = true;
            bool mid = true;
            bool right = true;

            for(int i=2;i<=5;i++){
                if(st.count(i)){
                    left = false;
                    break;
                }
            }

            for(int i=4;i<=7;i++){
                if(st.count(i)){
                    mid = false;
                    break;
                }
            }
            for(int i=6;i<=9;i++){
                if(st.count(i)){
                    right = false;
                    break;
                }
            }

            if(left && right){
               ans += 2;
            }else if(left || mid || right){
                ans += 1;
            }
        }

        ans += (n-(int)mp.size())*2;

        return ans;
    }
};