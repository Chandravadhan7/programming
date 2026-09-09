class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        int r = position[n-1];
        int s = speed[n-1];

        int ans = 0;

        for(int i=n-2;i>=0;i--){
            if(speed[i] > s || r-position[i] <= distance){
                r = position[i];
            }else{
                ans++;
                s = speed[i];
                r = position[i];
            }
        }
        return ans+1;
    }
};