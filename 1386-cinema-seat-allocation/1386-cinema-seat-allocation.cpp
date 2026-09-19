class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>> mp;
        for(auto x : reservedSeats){
            mp[x[0]].insert(x[1]);
        }

        int ans = 2*(n-mp.size());

        for(auto x : mp){
            bool k1 = true;
            for(int i=2;i<=5;i++){
                if(x.second.count(i)){
                    k1 = false;
                    break;
                }
            }
            bool k2 = true;
            for(int i=4;i<=7;i++){
                if(x.second.count(i)){
                    k2 = false;
                    break;
                }
            }

            bool k3 = true;
            for(int i=6;i<=9;i++){
                if(x.second.count(i)){
                    k3 = false;
                    break;
                }
            }
            if(k1 && k3){
                ans += 2;
            }else if(k1 || k2 || k3){
                ans++;
            }
        }
        return ans;
    }
};