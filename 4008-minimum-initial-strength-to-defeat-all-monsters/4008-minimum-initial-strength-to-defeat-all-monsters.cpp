class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        long long low = 0,high = 1e14;

        int n = monsters.size();
        vector<long long> diff(n+1,0);

        for(auto x : boosts){
            int l = x[0];
            int r = x[1];
            int v = x[2];

            diff[l] += (long long)v;
            diff[r+1] -= (long long)v;
        }

        for(int i=1;i<n;i++){
            diff[i] += diff[i-1];
        }

        long long ans = LLONG_MAX;

        while(low <= high){
            long long mid = low + (high-low)/2;

            long long curr = mid;
            bool can = true;

            for(int i=0;i<n;i++){
                if(curr + diff[i] >= monsters[i]){
                   curr -= monsters[i];
                   if(curr < 0){
                    curr = 0;
                   }
                }else{
                    can = false;
                    break;
                }
            }

            if(can){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};