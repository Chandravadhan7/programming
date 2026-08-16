class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int miin = INT_MAX;
        int idx = -1;

        for(int i=0;i<drones.size();i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];

            if(abs(target[0]-x)+abs(target[1]-y) <= range && abs(target[0]-x)+abs(target[1]-y) < miin){
                miin = abs(target[0]-x)+abs(target[1]-y);
                idx = i; 
            } 
        }
        return idx;
    }
};