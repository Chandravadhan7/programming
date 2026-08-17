class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int mx = *max_element(lights.begin(),lights.end());
        int ans = INT_MIN;

        for(int i=0;i<arrivalTime.size();i++){
            int val = arrivalTime[i]%period;
            if(val >= mx){
                ans = max(ans,period-val);
            }
        }

        return max(ans,0);

    }
};