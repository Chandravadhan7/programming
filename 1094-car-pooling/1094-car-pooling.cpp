class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int mx = INT_MIN;

        for(auto x : trips){
            mx = max(mx,x[2]);
        }

        vector<int> diff(mx+2,0);

        for(auto x : trips){
            int num = x[0];
            int l = x[1];
            int r = x[2];

            diff[l] += num;
            diff[r] -= num;
        }
        
        if(diff[0] > capacity){
            return false;
        }
        for(int i=1;i<mx;i++){
            diff[i] += diff[i-1];
            if(diff[i] > capacity){
                return false;
            }
        }

        
        return true;
    }
};